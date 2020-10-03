---
title: Agent Talk Free
permalink: /pages/4-tutorials/agents/talkfree.html
layout: series
index: 4.4.5
tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
    language: "C++"
    prev: /pages/4-tutorials/agents/agents001-002.html
    next: /pages/4-tutorials/agents/agentcalc.html
---

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
