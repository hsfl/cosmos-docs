---
title: Design Overview
permalink: /pages/documentation/cosmos-introduction.html
layout: page

tags: [software]
keywords: software
---


## Background

For many years following the first spacecraft launches by the original space faring nations, spacecraft size and complexity increased as more and more functionality was driven into each satellite and robotic explorer. We assume that this early trend was fueled at least partly by the fact that larger and larger launch vehicles could be constructed and launched to orbit and nations were willing and able to build these rockets. The budgets and political environments of this era allowed, and possibly even encouraged this trend.

Today however, we are witnessing a counter-trend with regards to spacecraft size. Resources required to develop and then lift large spacecraft on exceedingly costly launch vehicles are becoming increasingly constrained. But perhaps even more important, large spacecraft are no longer the only platforms available to execute scientific, technological, or defense missions. Partly driven by the ever-increasing capabilities of the shrinking integrated circuit and related technologies, small spacecraft can now be seriously considered to perform many of the missions that were traditionally the sole domain of large spacecraft. Further, novel space architectures are being considered using small spacecraft that were not even feasible using monolithic space platforms.

The ongoing evolution of small and very small spacecraft, typified by the university-developed Cubesat platform, is leading the charge for the transformation of the space technology and the aerospace industries. Cubesats, and small spacecraft platforms that can be accommodated on launch vehicles possessing excess launch performance margin as a secondary payload, embody a number of attractive features, the biggest of which is low development cost. Similarly, the creation of adapters and mechanisms such as the Poly Picosat Orbital Deployer (P-POD) for the deployment of Cubesats, and other devices such as the motorized Light Band from Planetary Systems Corporation, have facilitated the integration complexity and launch related aspects for small satellites and are making their accommodations relatively routine. However, as more and more small and very small spacecraft are being utilized by military and civil space, as well as educational institutions, there is a growing need for a low-cost, yet flexible method to operate these small spacecraft, potentially simultaneously as a constellation. Since the same cost constraints and pressures are at work, and expensive operations solution coupled with a low-cost development and launch capability does not make sense. Therefore, we need to apply the same innovative forces and techniques to the ground segment portion of the architecture that we have successfully implemented for the space segment. We anticipate that these innovative forces will take the form of novel development tools and environments, automation and smart systems and flight software, flexible ground networks and equipment, and universally accepted standards and approaches in order to enable low cost, widely accessible ground operations capabilities that are consistent with and build upon the momentum and value of the small spacecraft revolution.

The Hawaii Space Flight Laboratory (HSFL) of the University of Hawaii at Manoa is currently developing a comprehensive open set of software tools with supporting hardware that is designed to primarily support the operations of one or more small spacecraft, but can also perform an important role in the design, development, and testing phases of spacecraft missions. This set of mission operations tools operate within the architecture named COSMOS (Comprehensive Open-architecture Space Mission Operations System). COSMOS is being developed by HSFL in collaboration with NASA Ames Research Center (ARC) under a three-year NASA EPSCoR grant beginning in September, 2010. COSMOS will be particularly suited for small organizations with a very limited development and operations budget, such as universities. However, it is not just restricted to universities or educational activities. The COSMOS tools will initially be installed in two mission operation centers (MOCs) at HSFL and NASA ARC, and used in support of several small satellites from both organizations.
Spacecraft design and construction and subsequent mission support are all dependent on a number of unique protocols and technologies generally not found in Commercial-Off-The-Shelf (COTS) software. At the same time, although there is some significant overlap between the needs of all these activities, similar technologies are often used in markedly different ways, making tools incompatible at different phases, and leading to duplication of effort. As a result, tools for spacecraft design and mission support suffer from a number of flaws from the point of view of small missions developers. First among these is cost. While commercial packages capable of performing the COSMOS functions are available, they come at a high buy-in and maintenance costs. A second common flaw of many existing tools is that they are of limited scope. Often, two different tools that perform greatly similar functions will be required at different phases of the process. This serves not only to exacerbate the cost problem, but also leads to problems with integration, and with training. Finally, some areas, especially in mission support, are covered only by proprietary solutions, or not at all.


Although many universities operate their own small satellites, the operations systems are usually patched together using available general COTS applications, such as MATLAB®, LabView®, and MS Excel®, and are designed to be only sufficient to meet their immediate needs. COSMOS provides a solution that is being optimized from the beginning for mission operations and to add new and different types of satellites with minimum effort.

Other systems similar to COSMOS exist, such as ESA’s European Ground Operation System (EGOS)/Spacecraft Control Operation System (SCOS); JPL’s Advanced Multi-Mission Operations System (AMMOS); and GSFC’s General Mission Analysis Tool (GMAT). However, each of these has a problem for use with small satellite (university class) missions, such as restricted use, or unavailability of source code with requirement to have the system customized by provider. ESA’s Global Educational Network for Satellite Operations (GENSO) is a university class network currently being developed by several universities, but has some usage and operations limitations that are being addressed by COSMOS.



## Architecture and Design

## Tools

## Software Design

## Operations Test Bed
