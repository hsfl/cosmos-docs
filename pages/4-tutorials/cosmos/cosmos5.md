---
title: COSMOS Tutorial Part 5 - COSMOS Agents Advanced
permalink: /pages/4-tutorials/cosmos/cosmos5.html
layout: series

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
    language: "C++"
    prev: /pages/4-tutorials/cosmos/cosmos4.html
---

## COSMOS Agents

### Persistent Programs

COSMOS Agents are persistent programs that can run in different computer architectures (ex: Intel x86, ARM). Agents can send data across different platforms to collect data from your remote sensors or even send commands to control your node (ex: spacecraft).

### Data Transfer

There are mainly two mechanisms to transfer data between agents: 
* Post messages (HeartBeat, SOH)
* Request messages

Request messages can be divided into get value by request (embedded) request messages (user defined).

* **Post messages** can be divided into state of health (embedded/user defined) custom JSON (user defined) direct using binary or ascii (type must be > 127) (user defined) heartbeat (embedded/user defined).
* **Heartbeat messages** are the basic type of persistent information that each agent has. But heartbeat messages can be extended as defined by the user. 
* **State of health messages** (soh) carry larger packets of information, defined on a per-agent basis. Both heartbeats and soh messages run at a periodic interval.
* **Request messages** can be used to tailor the information exactly as requested by the user. Agent "a" sends a request to agent "b", and "b" responds with the specific information defined by the user. Requests are asynchronous and can be emitted at any time. Finally direct messages can be used to send any kind of information (including binary) through a direct channel connected between two or more agents that know the id for the message. This gives the most flexibility to the user with the expense of development time. Read Section 6.1 about sending commands to Agents.


## COSMOS Agent Program

The following are basic agent commands for retrieving data from the agents.

### List all the agents

This command will return the agents that are currently running on the network.

```bash
$ agent list
```

### List heartbeats

This command will print out the heartbeats of the currently running agents on the network. It prints on a per-agent basis, meaning it will organize the posted data by the agent process.

```bash
$ agent dump beat
```

### List state of health for other agents

This command will print out the state of health of the currently running agents on the network. Contrary to heartbeats, the state of health prints out an aggregated list of posted data of all agents.

```bash
$ agent dump soh
```

## Setup a new agent

Create a file `myprogram.cpp`. The Agent code should include the following:

```cpp
#include "agent/agentclass.h"

int main(int argc, char *argv[]) {
    Agent *agent;
    string nodename = "node_name_here";
    string agentname = "agent_name_here";

    agent = new Agent(nodename, agentname);
    string agent_name_here_soh = "{\"data_name_here\"}";
    agent->set_sohstring(agent_name_here_soh.c_str());

    while(agent->running())
    {
       /********************
        do something smart in here
       ********************/
    }
}
```

## Agent 001 and 002

We will now demonstrate how agent communication works by running both Agent 001 and 002. One will send data, and the other will receive it and display the output.

**Note**: If you have not set up a path to your cosmos bin folder, you will either have to set up a path (check Troubleshooting for the process) or move to the cosmos/bin folder and add ./ to the beginning of each command as follows:

$ ./agent_001

**Note**: If your antivirus repeatedly warns you about running a COSMOS exe, instruct your antivirus to ignore your COSMOS folder file path.

### In a terminal, start agent_001

```bash
$ agent_001
```

### In another terminal, start agent_002

```bash
$ agent_002
```

### Verify successful communication

agent_001 should be displaying:

```Received from agent_002: 16 bytes : hello 1 [OK]```

agent _002 should be displaying:

```agent_002 got request! response is: hello 1```

### Shutdown agents

In a new terminal, run the following commands to shutdown both agents.
```bash
$ agent cubesat1 001 shutdown
$ agent cubesat1 002 shutdown
```

### Look at the agent’s other commands 

Running the following command will print the commands you can run for this specific agent.
```bash
$ agent cubesat1 001
```

Read 6.1 Direct Commanding for more information on Agent Commands 

## Agent Talk Free

Send generic messages to the network.

You can use agent_post to broadcast specific information that does not fit into the COSMOS namespace format (ex: your payload counts the number of reboots and you want to collect that information easily over the network)

Just define your specific message type in one byte (ex: 0xBF), generate your data in a custom format for your parser and send it using agent_post.

```cpp
// generate data to broadcast
dataToBroadcast = "#PLD," + to_string(num_resets) + "*" + chksum;

// post information on the network with header 0xBF
iretn = agent_post(cdata, 0xBF, dataToBroadcast); 
```

```cpp
// receive new posts
iretn = agent_poll(cdata, meta, rxmessage, AGENT_MESSAGE_ALL, 1);

if (meta.type == 0xBF) {
    // do your stuff
}
```

## Agent Calc

We will now see how we can use agent requests to command a specific agent, specifically Agent Calc.

Before starting this tutorial, please make sure you built and installed the cosmos project, and that you have made a path to the cosmos/bin folder.

### Start agent_calc
Run the following command in a terminal. It will start the Agent Calc process:

```bash
$ agent_calc
```

### Run an Agent Calc request

Open a new terminal (command prompt) and query the agent 'calc' and wait for response:

```bash
$ agent null calc add 2 3
```
You can also use "sub", "mul", and "div" to subtract, multiply, and divide respectively, in the place of “add”.

To check if there is broadcast data in the network on linux:

```bash
$ sudo tcpdump host your_ip_address
```
(example broadcast address: 128.171.59.255) 

### Look at the agent’s other commands 

Run the following command to receive the commands:

```bash
$ agent null calc

help - list of available requests for this agent
	shutdown - request to shutdown this agent
	idle - request to transition this agent to idle state
	monitor - request to transition this agent to monitor state
	run - request to transition is agent to run state
	status - request the status of this agent
	getvalue {"name1", "name2", ... } - get specified value(s) from agents
	setvalue {"name1":value, "name2":value, ... } - set specified value(s) in		agent
	listnames - list the Namespace of the agent
	forward nbytes packet - Broadcast JSON packet to the default SEND port 		on local network
	echo utc crc nbytes packet - echo array of nbytes bytes, sent at time utc, 		with CRC crc
	nodejson - return description JSON for node
	statejson - return description JSON for State vector
	utcstartjson - return description JSON for UTC Start time
	piecesjson - return description JSON for Pieces
	devgenjson - return description JSON for General Devices
	devspecjson - return description JSON for Specific Devices
	portsjson - return description JSON for Ports
	targetsjson - return description JSON for Targets
	aliasesjson - return description JSON for Aliases
	add {value1} {value2} - adds two specified numbers together, returns 		result
	sub {value1} {value2} - subtracts two specified numbers, returns result
	mul {value1} {value2} - multiplies two specified numbers, returns result
	div {value1} {value2} - divides two specified numbers, returns result
```

### Agent CPU on Aerocore 

1. Cross compile UHABS5 project (link to git repo)
2. Deploy agent_cpu
3. Run agent_cpu on aerocore
4. Run # agent dump beat on your PC and you’ll see the CPU telemetry in JSON form format:

```
[BEAT][0] 57925.9468277076 cpu_duovero cpu 192.168.1.102 37811 59996
{"device_cpu_utc_000":57925.946816492433}{"device_cpu_maxgib_000":0.97126389}{"device_cpu_gib_000":0.082015991}{"device_cpu_maxload_000":1}{"device_cpu_load_000":0.02}{"device_disk_utc_000":57925.946816494892}{"device_disk_temp_000":300}{"device_disk_gib_000":0.29909897}{"device_disk_maxgib_000":7.1563492}
```

## Agent File 

The file transfer agent program, agent_file manages file transfers and message passing between COSMOS Nodes. Both file and message transfers are handles as an interchange of packets between two instances of agent_file.

Read: Transferring Files Between Computers

## Agent Forward 

The agent_forward program allows for monitoring of COSMOS Agents on a different network. All agents are forwarded bi-directionally between two computers. agent_forward needs to be run from two computers on two separate networks. 

Example: If you have an agent running on Computer 1 (C1) and you want to monitor the agent from Computer 2 (C2)

You will need the IP addresses of both computers. You can get it by entering  this command in the terminal: `/sbin/ifconfig`

The “inet” field  displays the computer’s current IP address.

agent_forward usage:

```bash
$ agent_forward 127.0.0.1
```

1. Run agent_forward on C1, replacing ‘127.0.0.1’ in the above command with the IP address of C2
2. Run agent_forward on C2, replacing ‘127.0.0.1’ in the above command with the IP address of C1
3. Verify: on C2 execute agent list, you should be able to see the same agents as C1


You can also use a free Amazon Web Services instance to test this capability at aws.amazon.com. 

1. Go to aws.amazon.com and create an account
2. Go to "Services" and select EC2
   1. On the left panel select "Instances" 
3. Click the blue "Launch Instance" button
4. Check the "Free tier only" checkbox on the left panel
5. Scroll down and select an instance with OS of your choice (Ubuntu 16.04 LTS works)
6. Keep default settings for testing, the only one that is important is security groups:
7. Change the "Source" from "Custom" to "My IP"
8. Click "Launch" and create a new private key. Store it somewhere you can remember. 
9. Once the instance is launched, you can ssh into the server using:

```bash
ssh -i path/to/your/privatekey.pem ubuntu@<AWS IP Address>
```

Afterwards, install COSMOS as usual on the remote server. The public IP is available on the EC2 dashboard. Continue with the tutorial using the previous steps.


