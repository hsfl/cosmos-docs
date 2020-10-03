---
title: Agent Calc
permalink: /pages/4-tutorials/agents/agentcalc.html
layout: series
index: 4.4.6
tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
    language: "C++"
    prev: /pages/4-tutorials/agents/talkfree.html
    next: /pages/4-tutorials/agents/agent_forward.html
---


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
