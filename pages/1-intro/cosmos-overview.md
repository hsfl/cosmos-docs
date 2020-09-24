---
title: 1. COSMOS Overview
permalink: /pages/1-intro/cosmos-overview.html
layout: page

#tags: [software]
keywords: software
toc: false
---

The Comprehensive Open-architecture Solution for Mission Operations Systems (COSMOS) is a software framework designed to control and operate robots - space orbiting robots, or better known as satellites!

COSMOS is an open-software framework designed to primarily support the development, mission operations and flight software of one or more small spacecraft. It is particularly suited for organizations with limited development and operations budget, such as universities. COSMOS is also designed to be used as a generic framework to operate heterogeneous architectures such as Satellite Ground Stations, Drones, Rovers, CanSats, BalloonSats, etc.

COSMOS is designed to be seamlessly integrated and compatible with multiple different assets or nodes such as satellites, unmanned air systems (UASs), ground control stations, computer stations, etc. and it is being expanded to address simulation scenarios with complex nodal architectures where events can be detected and trigger actions. It has been developed in the new paradigm of the network-of-things where any asset can be connected to the system in a “plug and play” approach, making it very generic for the inclusion and removal of assets/nodes. When a node is activated (and is COSMOS compatible), the whole system can be informed of its presence and receive telemetry that can be processed to take actions.

COSMOS is a suite of software tools (including external modules) that enables the operations team to interface with the spacecraft, ground control network, payload and other customers in order to perform the mission operations functions including mission planning and scheduling; contact operations; data management and analysis; simulations (including the operational testbed); ground network control; payload operations; flight dynamics; and system management. COSMOS is also being designed to be easily adapted for new spacecraft or installation in new mission operations centers (MOCs).

The following YouTube video shows some of the functionality of COSMOS. It shows various instances of the Mission Operations Support Tool (MOST) monitoring different CubeSats. At the end of the demo we bring up the COSMOS Executive Operator (CEO) to monitor all the CubeSats at once. But realize that COSMOS is much more than what you see in this demo. In fact COSMOS has become a middleware to enable robotic and embedded system operations. Click on the image below to open the youtube link and see it in full screen for a better experience.

<a href="https://www.youtube.com/watch?v=fJb2a5U4gSI" target="_blank"> {% include image.html file="/resources/cosmos-screenshot.png" width="100%" %} </a>

For a more detailed introduction of COSMOS please refer to the <a href="https://docs.google.com/document/d/1L4Zj18qiHuXaGP_LiW1hqxb7xOPx6wK19Tpp3RBvfVk/edit" target="_blank"> “COSMOS Introduction” </a> document. This will describe the philosophy behind COSMOS, the various Tools such as the Mission Operations Support Tool and the COSMOS Executive Operator.
