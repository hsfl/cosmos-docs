---
title: COSMOS Features
permalink: /pages/3-features/index.html
layout: page
index: 3.1

tags: [software]
keywords: software
---
## 3.1 COSMOS Elements
The COSMOS System is based on a number of key concepts, all acting in concert to provide a "COSMOS Aware" implementation. These concepts are realized through a set of libraries, programs and "rules of engagement" which will be explained below. Also included below are some examples of simple implementations that should serve to better explain the concept.

### 3.1.1 Nodes
A core concept of working with a complex system in COSMOS is "generalization". The idea is to generalize the parts of the system in to the minimum number necessary to achieve the desired goal. These parts are then each generalized as to the minimum number of qualities needed to accurately perform the task at hand. Each such generalized assemblage of parts is called a Node. Any "COSMOS Aware" software is cognizant of the Node it is working with, and can access the generalized information for that Node.

### 3.1.2 Pieces, Components and Devices
The first step in generalization is to describe a Node as a combination of specific physical Pieces, electrical Components and functional Devices. Each Node starts as a collection of "Pieces", each with a geometry (eg. box, sphere, etc.), associated dimensions and positions, a set of physical aspects (eg. mass, heat capacity, etc.) A subset of these pieces are, in turn, associated with Components, each with an associated electrical nature (eg. voltage, current, etc.). Finally, each Component is assigned a specific Device, which is assigned a set of attributes sufficient to represent its function. Device attributes are specific to each unique type of device(eg. Reaction wheel velocity, GPS position).

### 3.1.3 Namespace
Each unique aspect of each Piece, Component and Device, as well as any generalized aspects of the Node as a whole, are captured in a Nodal Namespace. This Namespace is then marshalled and unmarshalled between the memory spaces of the various running programs using JavaScript Object Notation, or JSON. The method for representing this Namespace in JSON format is defined in a set of rules. Namespace 1.0, our current set of rules, uses a flat, linear representation. In this representation, each attribute is its own unique JSON object, and is tied to a unique location in a structure in memory. The names follow a pattern of "type_attribute{\_###}", where type is one of
- node
- agent
- piece
- device_all
- device_{device}"
; attribute is any attribute (voltage, current, position, time); and ### is the index number for the piece, component or device.

### 3.1.4 Requests
Specialized commands, or "requests" are supported within COSMOS. Any COSMOS Aware application can use these Requests to request behavior that is specific to the particular COSMOS application that has been developed. Both requests, and any subsequent response, are delivered as regular ASCII strings. A standard set of Requests are built into all programs. Support is then provided for adding additional requests that are unique to a particular program.

### 3.1.4 Network Bus
COSMOS defines a specific usage of UDP packets that defines a "Network Bus" that allows the cross-communication of information and requests. This bus is built on the following elements:
- Standard UDP Port (10020) over which messages are broadcast. Primary among these are:
  - Heartbeat: a set of data that defines the particular program that is sending the Heartbeat. This includes:
    - Time
    - Node name
    - Process name
    - IP address
    - IP Port
  - State of Health (SOH): a JSON string providing a preset subset of the Namespace and the current values.
- Unique UDP Port over which Requests are accepted
- Standard predefined message types (indicated by first byte of message)

### 3.1.4 Agents
COSMOS has borrowed from modern operating systems by simple elaborating on many of their concepts. All modern operating systems support the concept of a persistent program that offers some sort of generalized service. COSMOS elaborates on this concept with "Agents". These are persistent programs that use the Elements defined in this section to make them part of COSMOS.

### 3.1.4 COSMOS Awareness
The way that COSMOS is used is through the process of making programs "COSMOS Aware". Any program can be made aware of COSMOS

## 3.2 COSMOS Core
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


## 3.4 COSMOS Tools
