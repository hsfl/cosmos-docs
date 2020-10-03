---
title: Setup a New Agent
permalink: /pages/4-tutorials/agents/new-agent.html
layout: series
index: 4.4.3
tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
    language: "C++"
    prev: /pages/4-tutorials/agents/agent-program.html
    next: /pages/4-tutorials/agents/agents001-002.html
---

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
