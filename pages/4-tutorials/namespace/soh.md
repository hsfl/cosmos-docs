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
## 1. Customizing SOH
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

## 2. Monitoring Agent SOH via Command Line
To check the data flow of the currently running agents you can use the agent program:
```
agent dump beat
```

This will show you the state of health information communicating with the heartbeat as the following example:

[BEAT]59129.7811441908:[hsflpc03:cpu][192.168.56.1:40643](251:900:0)
{"agent_utc":59129.7811441908,"agent_node":"hsflpc03","agent_proc":"cpu","agent_addr":"192.168.150.103","agent_port":40643,"agent_bprd":5.000000,"agent_bsz":59996,"agent_cpu":0.000000,"agent_memory":0.000000,"agent_jitter":0.000075,"node_utcoffset":0}
{"device_cpu_utc_000":0,"device_cpu_maxgib_000":25.370083,"device_cpu_gib_000":0,"memory_utilization_000":0,"cpu_utilization_000":0,"device_cpu_maxload_000":1,"device_cpu_load_000":0,"device_disk_utc_000":59129.781144184366,"device_disk_path_000":"","device_disk_gib_000":452797.59,"device_disk_maxgib_000":452797.59,"disk_utilization_000":1,"device_disk_utc_001":59129.781144184562,"device_disk_path_001":"\/boot\/efi","device_disk_gib_001":0.0058670044,"device_disk_maxgib_001":0.49900818,"disk_utilization_001":0.011757331131700455,"device_disk_utc_002":59129.781144184773,"device_disk_path_002":"\/","device_disk_gib_002":29.754356,"device_disk_maxgib_002":227.73599,"disk_utilization_002":0.13065284967288907,"device_disk_utc_003":59129.781144184934,"device_disk_path_003":"\/scratch","device_disk_gib_003":96.670853,"device_disk_maxgib_003":915.89136,"disk_utilization_003":0.10554838396253649}

We've put together a small agent example to demonstrate the principle.
Go to *cosmos/source/core/tutorials/agents/add_state_of_health* and open the **agent_add_soh.pro** in Qt creator.
