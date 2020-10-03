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
Example: (TO DO: update this example)


### Command Generator Script

### Command Generator Python Script

## Adding Commands to Command Queue via *add_event* Request

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
