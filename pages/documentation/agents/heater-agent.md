---
title: Heater Agent
permalink: /pages/documentation/agents/heater-agent.html

tags: [software, heater]
keywords: software

agent_name: agent_heater
---


## Description
The heater agent (AKA `agent_heater`) is an agent that handles the heater device. Should any temperatures fall too low, the heater agent will enable the heater. Later when the temperatures readings are sufficient, the heater agent will disable the heater. For the specific temperatures different events occur at, see the [temperature events table](#temperature-events)

The physical heater device is controlled using requests issued to the [switch agent](switch-agent.html) which, in turn, enables or disables the switched line for the heater.

All temperature values are retrieved from the [temperature sensor agent](temperature-sensor-agent.html).

## Temperature Events
Below is a table showing the temperatures various events occur at.

| Temperature (°C) |     Event      |
| ---------------- | -------------- |
|     10           | Heater Enable  |
|     20           | Heater Disable |


