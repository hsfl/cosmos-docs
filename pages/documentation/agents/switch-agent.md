---
title: Switch Agent
permalink: /pages/documentation/agents/switch-agent.html
layout: agent

tags: [software]
keywords: software

agent_name: agent_switch
---


## Description
The switch agent (aka `agent_switch`) is an agent that provides control to the switched lines in the EPS power distribution unit (PDU). Little is actually done inside of the main loop of this agent, as most functionality is performed through requests.

The PDU switched lines are controlled using several of the BeagleBone's GPIO pins. The switch agent internally either sets a GPIO pin HIGH to enable a switched line, or sets a GPIO pin LOW to disable it.


## Pin Mapping
Below is a table showing which GPIO pins control which switched lines:

| Switch Name | ID Number |   Physical Device   | GPIO Pin | PC104 Header Pin | PDU Switched Line |
| ----------- | --------- | ------------------- | -------- | ---------------- | ----------------- |
| `sw_heater` |     0     |        Heater       |  TODO    |       TODO       |       TODO        |
| `sw_temp`   |     1     | Temperature Sensors |  TODO    |       TODO       |       TODO        |
| `sw_ss`     |     2     |      Sun Sensors    |  TODO    |       TODO       |       TODO        |
