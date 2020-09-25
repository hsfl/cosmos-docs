---
title: COSMOS Features
permalink: /pages/3-features/index.html
layout: page

tags: [software]
keywords: software
---

## 3.1 COSMOS Core

core is organized into libraries and programs. The libraries provide the building blocks for everything done in COSMOS while the programs provide a basic set of essential command line programs to deploy COSMOS in any platform (core does not include graphic user interfaces).

- **COSMOS Agents**: persistent command line programs that can run in any platform (Linux, macOS, Windows, ARM, etc.) and interact with other agents on the network. The Agents can also control the hardware such as the ground station radio, antennas, satellite radio, satellite attitude control hardware, etc.
- **COSMOS Devices**: core provides a set of device drivers and libraries to connect to typical hardware (e.g. serial library, I2C library, CPU information library, disk, etc.)
- **COSMOS Math**: the Math library has the different mathematical functions to handle vectors, matrices, quaternions, least squares fitting, etc.
- **COSMOS Physics**: the Physics library provides features such as orbital propagation, attitude propagation, etc.
- **COSMOS Support**: most of the COSMOS features are bundled here. The Support library provides the basic configuration for setting up a COSMOS program (configCosmos.h), Coordinate Conversions, COSMOS errors handling, time utilities, Sockets, string handling, etc.

### 3.1.1 COSMOS Agents

COSMOS Agents are persistent programs that can run in almost any computer architecture (ex: Intel, ARM). With the agents you can quickly send data across different platforms to collect data from your remote sensors or even send commands to control your spacecraft.

- agent: Allows communication with any of the Agents on the local network.
  - acquire list of available agents
  - acquire request list
  - command specific agents
  - monitor agent traffic
- agent_cpu: Accepts requests to return the machine's:
  - virtual mem
  - virtual mem %
  - disk space used
  - disk space %
  - load
- agent_exec: Manages the execution of commands within the COSMOS system.
  - Manages a command queue driven by time and conditions.
  - commands can be added or removed from queue through direct requests or through command files
- agent_file: Manages file transfers and message passing between COSMOS Nodes.

#### 3.1.2 Ground Station Agents

- agent_control: main agent that controls the ground station. It is the channel for the T&C and it is also responsible for the agent_antenna and agent_radio
- agent_antenna: Controls the ground station antenna
  - sets elevation
  - get/set azimuth
  - (direction)
- agent_radio: Controls the ground station radio
  - frequency
  - power


#### 3.1.3 General Programs

- command_generator: Feeds commands into the command queue managed by agent_exec
- cosmos_size: calculates the # of bytes used by cosmos
- devstruct_size: prints # of bytes used by each devstruct
- fast_propagator: takes data from a given node and propagates an torbit
- gige_list: lists camera info
- gige_snap: configures and uses camera(s)
- netperf_listen & netperf_send: used to receive/send UDP/IP packets on port 6101 by default
- used for sending/gathering statistics
- auto-timeout used to end session
- propagator: Uses state data from a node to propagate an orbit
- serial_listen: listens to a port? prints items, and keeps counts of reads, timeouts, and errors
- tle2state: takes in a tle, converts to eci, outputs eci in json

### 3.1.4 Test Programs

- lsfittest: calculate a ls fit
- mathspeed: test device/computer speed
- netspeed & netspeedd: checks and prints the speed of connection

### 3.1.5 COSMOS Namespace

The Namespace is used to represent the data incoming and outgoing from different locations (sensors, servers, databases) through the JavaScript Object Notation (JSON). JSON was selected to be used since it is lightweight, succinct, and agnostic.

#### 3.1.6 Generalization
The namespace aims to represent a general understanding of the data. For example, we might want to represent the positional data of the node.

#### 3.1.7 Hierarchy
Nodes can be thought of as processors/computers in physical locations. Each Node contains Pieces, which represent the individual elements that make up the Node. These Pieces are further sub-categorized as Components and Devices. In the following text, further explanation is offered on each level.

##### 3.1.7.1 Node
The Node is the top level of the namespace. Generally, it is a computer that is capable of running agents. In addition, it offers a summary of the node, for example the moment of inertia or its location.

Example: node_loc_pos_x, node_moi_x

##### 3.1.7.2 Agents
An agent’s main purpose is to interface with low level devices, such as the power supply or a radio (e.g. send commands and receive data). It is a persistent program that maintains bidirectional control of the devices.

It can place the received data into the namespace for later consumption.

##### 3.1.7.3 Broadcasts
Agents have the ability to broadcast data at a certain interval to broadcast data from a node, called the “state of health.” It contains a snapshot of data at a certain time in JSON format.

##### 3.1.7.4 Requests
Agents can handle incoming requests, typically used to engage a change of state of the agent. For instance, an agent might currently be processing data, but if a sensor is ready to retrieve data, an agent request could shift its resources from processing data to retrieving data.

##### 3.1.7.5 Pieces
A piece is a subset of a node. It describes individual subsystems within a node such as the dimensions or mass of a power supply. 

A piece
Contains a:
Name
Component (device) index

Example: piece_...

##### 3.1.7.6 Components 
Components are a subset of a piece. It describes the electrical components of a piece, such as the voltage, amperage or power.

##### 3.1.7.6 Devices (General)
A general device is a subset of a piece. It organizes values from piece sensors. For example, a GPS device could collect positional or velocity data.
Example: devgen_...

##### 3.1.7.6 Devices (Specific)
A specific device is also a subset of a piece.

##### 3.1.7.6 Alias
An alias is like an equation creator. You can calculate new values based on currently available namespace values. For example, you could calculate the power based on the voltage and amperage.

## 3.3 COSMOS Tools

The COSMOS Tools are the graphic user interface (GUI) tools to enable the user to operate the spacecraft and the COSMOS Agents.

- COSMOS Web
