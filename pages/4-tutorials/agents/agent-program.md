---
title: Agent Program
permalink: /pages/4-tutorials/agents/agent-program.html
layout: series
index: 4.4.2
tags: [software]
keywords: software

sidebar: home_sidebar
toc: false

series:
    language: "C++"
    prev: /pages/4-tutorials/agents/overview.html
    next: /pages/4-tutorials/agents/new-agent.html
---


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
