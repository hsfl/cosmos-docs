---
title: Executive Command Queue
permalink: /pages/4-tutorials/commands/command-queue.html
layout: series
index: 4.5.2
tags: [software]
keywords: software
series:
    language: "C++"
    prev: /pages/4-tutorials/commands/commanding.html
---

## Agent Exec (agent_exec)
The process **agent_exec** is an Agent that maintains a queue of commands. At a rate set by the Agent Period, this queue is searched for any commands whose execute UTC has been exceeded. Commands on the command queue are typically executed with 100 ms granularity. If any command in this short list has an optional condition, it is checked as well, and if zero, ignored. Finally, any commands that have already been run are ignored. Any commands left in the queue are executed, and then removed unless marked as repeating. Commands are entered into the queue as a Command Event in one of two ways:
1. First they can be sent as a request via direct commanding to agent_exec using  
```
agent NodeName exec add_event ...
```
2. Second, they can be stored in a file with a `.command` extension and placed in the *~/cosmos/nodes/incoming/exec* subfolder. They will then be loaded into the command queue within the next Agent Period.

 Any command that is run will be logged in two separate locations. A command event record will be added to a command event file (“.event”). The actual output of the command will be added to a command output file (“.log”). Both files will be placed in the *temp/exec* subfolder of the node folder, and then periodically moved to the *outgoing/exec* subfolder.

## Creating Commands
There are four different ways to generate commands. There are three command generators that operate the same but written in different programming languages.
### Command Generator Program
Run the command generator:
```
$ command_generator
```
Example: Create a test command using the *command_generator* program to create a command to command an agent.
For this example, we will use Agent CPU and request the CPU load from it.

Start *agent_cpu*. Open a terminal and run
```
$ agent_cpu
```
Find the **node** by opening another terminal and running `agent list`. Find the *cpu* agent and take note of the node name.
The Agent CPU request we will use in the command is `load`. Test it by running `agent  <nodename> cpu load`.

Now, use the command generator to create the command. Run the following in a terminal and replace <nodename> with the node of your cpu agent.  
```
$ command_generator test_command "agent <nodename> cpu load" +60
```
The `+60` argument will set the time of the command to sixty seconds from now. If you leave out this argument, the command will be generated with time 0, it will be executed immediately.

The output should give you something like this:
```
Command string:
{"event_utc":59128.046385,"event_name":"test_command","event_type":8192,"event_flag":0,"event_data":"agent nodeName cpu load"}
```
Copy the JSON structure that is output from the command generator. Create a new file `test_command.command` file in `~/cosmos/nodes/<nodename>/incoming/exec`

```
$ vi ~/cosmos/nodes/<nodename>/incoming/exec/test_command.command
```
Next, start *agent_exec* with the same nodename as your cpu agent
```
$ agent_exec <nodename>
```
You will see in the terminal, your command added by the agent. After the command is executed, the file will no longer be in the `...incoming/exec` directory that you put it in. Check for the output file in `outgoing/exec` or `temp/exec` the output will be in a file with the `.out` suffix. Agent Exec temporarily stores the output in the `temp/exec` directory in the nodes folder. Periodically, the files are then moved to the `outgoing/exec` directory.

The text in this file should be identical to the output of the command run from a terminal.


### Command Generator Script

An alternative to generate commands is to use the *command_generator.sh* script in the folder: *cosmos/source/core/scripts/*

Example: Create a test command using the *command_generator* program to create a command to command an agent.
For this example, we will use Agent CPU and request the CPU load from it.

Start *agent_cpu*. Open a terminal and run
```
$ agent_cpu
```
Find the **node** by opening another terminal and running `agent list`. Find the *cpu* agent and take note of the node name.
The Agent CPU request we will use in the command is `load`. Test it by running `agent  <nodename> cpu load`.

Run the command generator script:
```
$ ./command_generator.sh
```
You will encounter a series of prompts
```
Please enter an event name:     test
```
The event name is arbitrary
```
Please enter a UTC time:        0
```
UTC Time  is the time to execute the command. Time 0 means execute immediately, time `+10` means 10 seconds into the future.
```
What is the event command?      "agent <nodename> cpu load"
```
Event Command: enter the full command you wish to execute. Encapsulate in quotes if there are spaces.

Event Repeatability / Condition: An event must be conditional to be repeatable. Conditions must be formatted as `(”device_bus_power_003”=0)`, enclosed in parentheses. To refer to an item in the COSMOS namespace as an operand, enclose the item in parentheses.  
```
Is your event repeatable? (y/n):    n
Is your event conditional? (y/n):   y
```
this will generate a *autogen.command* file in the current directory.
To add this command to the command queue, move the *autogen.command* file that was just created into the directory: *cosmos/nodes/<nodename>/incoming/exec*

Next, start *agent_exec* with the same nodename as your cpu agent
```
$ agent_exec <nodename>
```
You will see in the terminal, your command added by the agent. After the command is executed, the file will no longer be in the `...incoming/exec` directory that you put it in. Check for the output file in `outgoing/exec` or `temp/exec` the output will be in a file with the `.out` suffix. Agent Exec temporarily stores the output in the `temp/exec` directory in the nodes folder. Periodically, the files are then moved to the `outgoing/exec` directory.

The text in this file should be identical to the output of the command run from a terminal.

### Command Generator Python Script
Another alternative is to use the python script *command_generator.py* in the directory: *cosmos/source/core/scripts/*

```
$ python command_generator.py
```
You should see :
{% include image.html file="/resources/tutorials/cosmos/command_generator.png" width="100%" %}
Fill in the fields and hit “ENTER” to move on to the next block

This will generate a command file (.command) in the current directory.
To add this command to the command queue, move the *.command* file that was just created into the directory: *cosmos/nodes/NodeName/incoming/exec*

## Adding Commands to Command Queue via *add_event* Request
Commands added through requests must be passed as JSON string with their quotes escaped. This can be done by wrapping the entire argument in single quotes. An example is given below:
```
$ agent neutron1 exec add_event ‘{“event_name”:”diskSize”}{“event_utc”:0}{“event_utcexec”:0}{“event_flag”:0}{“event_type”:8192}{“event_data”:”agent neutron1 cpu diskSize”}{“event_condition”:””}’
```
If the argument is correctly interpreted as a string, you will get the following output back:
```
Command added to queue: {“event_name”:”diskSize”}{“event_utc”:0}{“event_utcexec”:0}{“event_flag”:0}{“event_type”:8192}{“event_data”:”agent neutron1 cpu diskSize”}{“event_condition”:””}[OK] ...
```
The inverse request (‘del_event’) should also format this argument by escaping its quotes.

## Managing the Command Queue

### Getting the size of the Command Queue
To determine the current size of the queue, use the `get_queue_size` request of Agent Exec
```
$ agent neutron1 exec get_eueue_size
```

### Getting a list of events in the queue
To view what events are in the queue, use the `get_event` request without arguments
```
agent neutron1 exec get_event
```
The output should look something like this:
```
$ agent neutron1 exec get_event
[0][2023-02-25T00:00:00]{"event_utc":60000}{"event_utcexec":0}{"event_name":"diskSize"}{"event_type":8192}{"event_flag":0}{"event_data":"agent neutron1 cpu diskSize"}{"event_condition":""}
[1][2023-02-25T00:00:00]{"event_utc":60000}{"event_utcexec":0}{"event_name":"diskSize"}{"event_type":8192}{"event_flag":0}{"event_data":"agent neutron1 cpu diskSize"}{"event_condition":""}
[2][2023-02-25T00:00:00]{"event_utc":60000}{"event_utcexec":0}{"event_name":"diskSize"}{"event_type":8192}{"event_flag":0}{"event_data":"agent neutron1 cpu diskSize"}{"event_condition":""}
.
```

### Get an event
To view which event occupies the nth position in the queue, use the `get_event` with an additional parameter `n`
Example: n = 0
```
$ agent neutron1 exec get_event 0
```
The request will output the event in that spot of the queue
```
[2023-02-25T00:00:00]{"event_utc":60000}{"event_utcexec":0}{"event_name":"diskSize"}{"event_type":8192}{"event_flag":0}{"event_data":"agent neutron1 cpu diskSize"}{"event_condition":""} [OK]
```

### Deleting an event in the queue
To delete an item in the queue based on its current position, use the `del_event_id` request with the position parameter `n`
To delete the event in position 0:
```
$ agent neutron1 exec del_event_id 0
```
To delete an item in the queue based on the event JSON string, use the `del_event` request. This will delete ALL events whose JSON string matches (i.e. duplicates).
```
$ agent neutron1 exec del_event {"event_utc":60000}{"event_utcexec":0}{"event_name":"diskSize"}{"event_type":8192}{"event_flag":0}{"event_data":"agent neutron1 cpu diskSize"}{"event_condition":""}
```
The request will output the following:
```
1 commands deleted from the queue[OK] ...
```

### Agent Exec Buffer
By default, the output of events are logged to *~/cosmos/nodes/NODE_NAME/temp/exec*. **agent_exec** is then responsible for moving and compressing the output files to *~/cosmos/nodes/NODE_NAME/incoming/exec*. The rate at which **agent_exec** flushes this buffer can be seen using the `get_logstride_exec` request.
```
$ agent neutron1 exec get_logstride_exec
```

To flush the buffer faster or slower, use the `set_logstride_exec` request:
```
$ agent neutron1 exec set_logstride_exec
```
