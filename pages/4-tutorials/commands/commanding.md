---
title: Direct Commanding
permalink: /pages/4-tutorials/commands/commanding.html
layout: series
index: 4.5.1
tags: [software]
keywords: software
series:
    language: "C++"
    next: /pages/4-tutorials/commands/command-queue.html
---


Each Agent listens for requests over a network port determined at random when it launches. This port can be discovered by listening to the heartbeats delivered by Agents at regular intervals.
## Agent Requests
- To access this process from the command line, make use of the `agent` program.
- Each Agent running will have a unique combination of **NodeName** and **AgentName**.  
- There are a certain set of requests that all Agents will respond to.
- Get a list of available Agents:
 ```
 agent list
 ```
  This will display a variety of parameters about each Agent, the most important of which are their **NodeName** and **AgentName**. Each Agent running will have a unique combination of **NodeName** and **AgentName**.

## List Available Requests
- Each Agent can be programmed to respond to a variety of additional requests. The function and calling format of all of these requests are available through:
```
$ agent NodeName AgentName
```
- Running this command with no additional arguments will list all available requests that can be made to the Agent.

To make a request to an Agent with **AgentName** and **NodeName**, where **request**=request string, **args=request arguments(if any) :
```
$ agent NodeName AgentName request args
```
