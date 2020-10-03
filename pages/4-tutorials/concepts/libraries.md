---
title: Libraries
permalink: /pages/4-tutorials/concepts/libraries.html
layout: series
index: 4.1.2
tags: [software]
keywords: software
series:
    language: "C++"
    prev: /pages/4-tutorials/concepts/time.html
    next: /pages/4-tutorials/concepts/errors.html
---

The libraries used in COSMOS are split into different directories based on the data they hold. These directories are:

- agent
- device
- math
- physics
- support
- thirdparty

The **agent** directory holds codes pertaining to the agent class. It defines the agent class as well as the scheduler queue.

The **device** directory holds codes pertaining to different hardware that COSMOS could potentially be loaded onto.

The **math** directory holds codes pertaining to useful math functions/concepts, such as quaternions, vectors, matrices, conversions and some useful constants.

The **physics** directory holds codes pertaining to useful physics functions. This includes some commonly used constants, orbit calculations, inertia calculations, gravity calculations, etc.

The **support** directory holds codes pertaining to different data structs and classes, constants, error codes, functions, etc. that is needed to run the many (core) parts of cosmos.

The **thirdparty** directory holds codes pertaining to jpeg, png, and zlib files
