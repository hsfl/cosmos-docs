---
title: Development Environment
permalink: /pages/documentation/other/development-environment.html
layout: page

keywords: software
---

## Introduction

The development environment collectively refers to an [Ubuntu 18.04.4](https://en.wikipedia.org/wiki/Ubuntu_version_history#Ubuntu_18.04_LTS_(Bionic_Beaver)) disk image, and the tools and flight software it contains. Most of the setup and installation is already taken care of in this image.

For the installation process, visit the [setup tutorial]({{site.baseurl}}/pages/tutorials/setup/setup2.html).

## What's Inside

* Flight Software
  * BeagleBone Software
    * Agent source code
  * Raspberry Pi Software
    * Artemis Python Library
    * Example camera script
  * PyCubed Software
    * Main code
* COSMOS
  * COSMOS Core
  * COSMOS Web
  * SimpleAgent template project
* Other
  * Qt Creator
    * ARM Cross Compiler
  * Utility Scripts
  * MongoDB Server
  * Doxygen
  * CMake


## Built-In Scripts

### Update Script

This script updates the local copy of the cubesat kit repository. If you want to update your software, use this script.

Location: home directory
Usage:

```bash
$ ./update
```
