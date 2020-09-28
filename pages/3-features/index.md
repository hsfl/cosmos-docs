---
title: COSMOS Features
permalink: /pages/3-features/index.html
layout: page

tags: [software]
keywords: software
---
## 3.1 COSMOS Elements
The COSMOS System is based on a number of key concepts, all acting in concert to provide a "COSMOS Aware" implementation. These concepts are realized through a set of libraries, programs and "rules of engagement" which will be explained below. Also included below are some examples of simple implementations that should serve to better explain the concept.

### 3.1.1 COSMOS Nodes
A core concept of working with a complex system in COSMOS is "generalization". The idea is to generalize the parts of the system in to the minimum number necessary to achieve the desired goal. These parts are then each generalized as to the minimum number of qualities needed to accurately perform the task at hand. Each such generalized assemblage of parts is called a Node. Any "COSMOS Aware" software is cognizant of the Node it is working with, and can access the generalized information for that Node.

### 3.1.2 Pieces, Components and Devices
The generalization is ultimately achieved by assigning a "Device" to each required piece of hardware. Each Device is in turn assigned a set of attributes sufficient to represent its function. These attributes are both general in nature (eg. voltage, current, etc.) and specific (eg. Reaction wheel velocity, GPS position). In order to fully simulate all aspects of a Nodal system, the generalized description actually includes a physical aspect as well. Each Node starts as a collection of "Pieces", each with a geometry (eg. box, sphere, etc.) and associated dimensions, as well as physical aspects (eg. mass, heat capacity, etc.) Some of these pieces (though not necessarily all) are associated with electronic "Components", each with an assoicated electrical nature. Finally, each Component is assigned a specific Device.
### 3.1.1 COSMOS Namespace
COSMOS uses a predefined Namespace in order to handle the marshalling and unmarshalling of data between different systems, and to provide a unique expression of all the attributes of all the Pieces, Components and Devices in a Node. We have chosen to represent this Namespace usnig JavaScript Object Notation, or JSON. A set of rules has been defined for the representation of each attribute, using JSON. We are currently using a flat representation, which we call Namespace 1.0. In this representation, each attribute is its own unique JSON object, and is tied to a unique location in a Namespace structure in memory. The names follow a pattern of "type_attribute{_###}", where type is one of "node", "agent", "piece", "device_all", "device_{device}"; attribute is any attribute (voltage, current, position, time); and ### is the index number for the piece, component or device.

## 3.2 COSMOS Core
core is organized into libraries and programs. The libraries provide the building blocks for everything done in COSMOS while the programs provide a basic set of essential command line programs to deploy COSMOS in any platform (core does not include graphic user interfaces).
- **COSMOS Agents**: persistent command line programs that can run in any platform (Linux, macOS, Windows, ARM, etc.) and interact with other agents on the network. The Agents can also control the hardware such as the ground station radio, antennas, satellite radio, satellite attitude control hardware, etc.
- **COSMOS Devices**: core provides a set of device drivers and libraries to connect to typical hardware (e.g. serial library, I2C library, CPU information library, disk, etc.)
- **COSMOS Math**: the Math library has the different mathematical functions to handle vectors, matrices, quaternions, least squares fitting, etc.
- **COSMOS Physics**: the Physics library provides features such as orbital propagation, attitude propagation, etc.
- **COSMOS Support**: most of the COSMOS features are bundled here. The Support library provides the basic configuration for setting up a COSMOS program (configCosmos.h), Coordinate Conversions, COSMOS errors handling, time utilities, Sockets, string handling, etc.
### 3.1.1 COSMOS Agents

### 3.1.2 Ground Station Agents

### 3.1.3 General Programs

### 3.1.4 Test Programs


## 3.4 COSMOS Tools
