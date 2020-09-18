---
title: COSMOS
permalink: /pages/documentation/cosmos/cosmos.html
layout: page

tags: [cosmos]
keywords: software, documentation, cosmos
---

## What is COSMOS?

COSMOS (_Comprehensive Open-architecture Solution for Mission Operations Systems_) is a missions toolkit
created by Hawaii Space Flight Laboratory at the University of Hawaii at Manoa. In the context of the
Artemis Cubesat Kit, it is used to build flight software running on the BeagleBone.

COSMOS itself does not have a GUI, but a relatively new development called [COSMOS Web](cosmos-web.html)
provides a nice web-based user interface for COSMOS missions.

## Concepts Used

### Nodes

A node in COSMOS typically corresponds to a physical computer or other grouping of objects. For example, a satellite
and a ground station would each have their own respective nodes. In the Artemis Cubesat Kit, the cubesat node is
simply called `cubesat`.

### Devices

Devices in COSMOS represent physical devices. COSMOS devices are used to group together various device-specific properties
and store information about them. For example, a physical temperature sensor device has a corresponding COSMOS temperature sensor device, which has (among others) a _temperature_ property.

There are many different types of devices supported by COSMOS. A list of COSMOS devices supported by the SimpleAgent
utility class is located in the [SimpleAgent device documentation]({{site.folder_docs_utility}}/simpleagent-devices.html).

As not every physical device has a corresponding COSMOS device, this can make things tricky. There is limited support for
custom devices, but if you want to add full support for your device you will need to edit the COSMOS Core source code
yourself. There is a tutorial on this linked from the [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI).


### Agents

An agent is a special program that performs some particular task, and reports back. Different agents can communicate with each other over a COSMOS node. Agents running on different nodes can communicate with each other as well.

The way agents report back their values is through the _state of health_ mechanism. In SimpleAgent, this is called _posting_ a property. Posting a property will allow external programs to view data stored in an agent, either through the command line, another agent, or with [COSMOS Web](cosmos-web.html).

If we want to ask another agent (in a separate process/program) to do something, we can do so using _requests_. A request is a simple function that takes some arguments and outputs a value, as with a regular old function. The main difference is that a request is a function belonging to an agent that you can call externally (not in the same program).

Typically we write one agent corresponding to a particular hardware device, or class of hardware device. For example, in the Artemis CubeSat Kit there are six sun sensors. To handle these, we've written a [sun sensor agent]({{site.folder_docs_agents}}/sun-sensor-agent.html), which handles all of the operations of the sun sensor: initializing the hardware devices, reading and writing values, and reporting these values.


## See Also
* [COSMOS Manual](https://docs.google.com/document/d/19rqvtZeEMJzkEcsTlC4ojYUkN-3OcYLc6IqRXgDIQlI)
* [COSMOS Project](http://cosmos-project.org/)
* [SimpleAgent Documentation]({{site.folder_docs_utility}}/simpleagent.html)
* [SimpleAgent Device Documentation]({{site.folder_docs_utility}}/simpleagent-devices.html)