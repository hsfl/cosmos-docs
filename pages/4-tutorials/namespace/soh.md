---
title: State of Health (SOH) Messages
permalink: /pages/4-tutorials/namespace/soh.html
layout: series
index: 4.6.1
tags: [software]
keywords: software
series:
    language: "C++"
    next: /pages/4-tutorials/namespace/create-node.html
---

This is a tutorial to show you how to use State of Health messages in the COSMOS Agents.
## Customizing SOH
you can add your personalized state of health (SOH) information using the function agent_set_sohstring. Example:
```
// Set SOH String
std::string soh = "{\"node_loc_utc\","
			"\"node_loc_pos_eci\","
			"\"node_loc_att_icrf\"}" ;
agent->set_sohstring(soh);
```

inside the main loop you can assign the desired dynamic information:
```
// Start executing the agent
while(agent->running())
{

    pos_eci.utc = currentmjd(0);

    cartpos pos_eci;
    pos_eci.s.col[0] = 1000;
    pos_eci.s.col[1] = 2000;
    pos_eci.s.col[2] = 3000;

    agent->cinfo->pdata.node.loc.pos.eci = pos_eci;
}
```
An example could be found in cosmos-core at `cosmos/source/core/tutorials/agents/agent_add_soh`
