---
title: COSMOS Agents Overview
permalink: /pages/4-tutorials/agents/overview.html
layout: series
index: 4.4.1
tags: [software]
keywords: software

sidebar: home_sidebar
toc: false

series:
    language: "C++"
    next: /pages/4-tutorials/agents/agent-program.html
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
