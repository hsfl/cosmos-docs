---
title: Agent Forward
permalink: /pages/4-tutorials/agents/agent_forward.html
layout: series
index: 4.4.7
tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
    language: "C++"
    prev: /pages/4-tutorials/agents/agentcalc.html
    next: /pages/4-tutorials/agents/agent_file.html
---




## Agent Forward

The agent_forward program allows for monitoring of COSMOS Agents on a different network. All agents are forwarded bi-directionally between two computers. agent_forward needs to be run from two computers on two separate networks.

Example: If you have an agent running on Computer 1 (C1) and you want to monitor the agent from Computer 2 (C2)

You will need the IP addresses of both computers. You can get it by entering  this command in the terminal: `/sbin/ifconfig`

The “inet” field  displays the computer’s current IP address.

agent_forward usage:

```bash
$ agent_forward 127.0.0.1
```

1. Run agent_forward on C1, replacing ‘127.0.0.1’ in the above command with the IP address of C2
2. Run agent_forward on C2, replacing ‘127.0.0.1’ in the above command with the IP address of C1
3. Verify: on C2 execute agent list, you should be able to see the same agents as C1


You can also use a free Amazon Web Services instance to test this capability at aws.amazon.com.

1. Go to aws.amazon.com and create an account
2. Go to "Services" and select EC2
   1. On the left panel select "Instances"
3. Click the blue "Launch Instance" button
4. Check the "Free tier only" checkbox on the left panel
5. Scroll down and select an instance with OS of your choice (Ubuntu 16.04 LTS works)
6. Keep default settings for testing, the only one that is important is security groups:
7. Change the "Source" from "Custom" to "My IP"
8. Click "Launch" and create a new private key. Store it somewhere you can remember.
9. Once the instance is launched, you can ssh into the server using:

```bash
ssh -i path/to/your/privatekey.pem ubuntu@<AWS IP Address>
```

Afterwards, install COSMOS as usual on the remote server. The public IP is available on the EC2 dashboard. Continue with the tutorial using the previous steps.
