---
title: FAQ
permalink: /pages/8-help/faq.html
layout: page
index: 8.2

tags: [software]
keywords: software
---

## What exactly does a namespace do?
The COSMOS namespace is a collection of variables that will contain the relevant information for your project. The namespace is important because it enables a device running COSMOS in place-A to communicate properly to device in place-B, the namespace is shared. Examples of "names" are Time, Temperature, Position, etc. In a way, it's a "container" (a structure in C-code) for the data you're interested in.
## The namespace variable for the imu temperature in this case, is "device_imu_temp_000"
The typical format for a namespace name will be just like you described. "device_imu_temp_001" will be for the temperature of a second imu, etc. At this point there is no quick and easy way to check for a list of devices you can use. Better talk to us or look into the code.
## when you're receiving the state-of-health information, how do you know what piece of data is what?
Such as in the example beat:
```
{"agent_utc":57245.1587221274}{"agent_node":"telem"}{"agent_proc":"add_soh"}{"agent_addr":"192.168.56.1"}{"agent_port":61686}{"agent_bsz":59996}{"node_utcoffset":0}{"node_loc_utc":0}{"node_loc_pos_eci":{"utc":57245.158722127439,"pos":[4,5,6],"vel":[0.10000000000000001,0,0],"acc":[,4.9406564584124654e-323,1.8041870288084286e-307]}}{"node_loc_att_icrf":{"utc":0,"pos":{"d":{"x":0,"y":0,"z":0},"w":0},"vel":[0,0,0],"acc":[0,0,0]}}
```
I can kind of guess the variable names, such as acc is acceleration, utc is coordinated universal time, and vel is velocity, etc., but what are the "node_loc_att_icrf" and "node_loc_pos_eci" things?

- node_loc_att_icrf - means, this node / location / attitude / International Celestial Reference Frame
- node_loc_pos_eci - mean, this node/ location / position / Earth Centered Inertial

These two are basically the same position but in different spatial reference frames.


## I've installed SourceTree and logged on to BitBucket, and I can't find the COSMOS repositories. Any suggestions?
After putting your credentials in SourceTree it will not show the COSMOS repositories automatically. You have to manually add them as described in step 3). This is a bit confusing because when you login into the BitBucket website it will actually show you the COSMOS repositories, given that you have been granted access to the COSMOS repos.
