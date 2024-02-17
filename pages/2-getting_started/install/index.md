---
title: "COSMOS Core Install"
permalink: /pages/2-getting_started/install/index.html
index: 2
layout: page
sidebar: home_sidebar
tags: [software]
keywords: software
---

## Overview

You can install COSMOS from scratch using the following instructions. Alternatively you can get COSMOS via the [development environment](https://hsfl.github.io/cosmos-docs/pages/2-getting_started/development-environment.html). 

<!--{% include warning.html content="It is still _highly_ recommended that you install COSMOS on Ubuntu 18.04.3 for compatibility." %}-->


<!--## Installation
Installing COSMOS core is easy it can be done from the sources repository. Follow the link to your OS:
-->
## Getting Started

We recommend installing COSMOS via Docker. By using Docker containers you will get all the COSMOS dependencies automatically resolved. This process works well for users and developers.

**Windows/MacOS**

* [Install Docker Desktop](https://www.docker.com/get-started/)

**Linux**
* [Install Docker Compose](https://docs.docker.com/compose/install/)


## Install Instructions (via Docker)

**Windows Instructions:** 

You can use the same installation instruction as Linux/MacOS after [installing Windows Subsystem for Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install). Read the section **Check which version of WSL you are running** on the linked page to double check which distro you are using (Ubuntu recommended). Docker Desktop may change the default distro to something else, in which case you will need to set it to Ubuntu using the instructions in that section.

**Linux/MacOS/WSL Instructions:** 

Open a terminal window (Linux/MacOS) or a WSL terminal (Windows) and enter the following command to clone this repository to the home folder.

Clone cosmos to the home folder ~/cosmos-docker (recommended path)
```bash
git clone https://github.com/hsfl/cosmos.git ~/cosmos-docker
```

**AFTER you have completed the prior steps, continue with the following steps. Note these steps are the same for both operating systems.** 


1. Change directories to the newly cloned folder:

```bash
cd ~/cosmos-docker
```

2. Copy the .env.example file and name it .env. Nothing needs to be changed as of yet.
```bash
cp .env.example .env
```

3. Next, run the following command to get the containers running.
```bash
docker compose up -d
```

You may confirm that the cosmos_core container is running by either checking the running containers in Docker Desktop, or by running the following command:
```bash
docker ps
```

> If you are getting an error that looks like this:
> ```Got permission denied while trying to connect to the Docker daemon...```
> This is because your user has not been added to the *docker* group that is required after the Docker installation. Run the following command to add the current user to the *docker* group:
>
> ```sudo usermod -aG docker $USER```
>
> Close the terminal window and reopen another terminal window to complete the process. You can confirm that your user is in the *docker* group by running the command:
> ```bash
> groups
> ```
> Retry steps 1-3

## Demo

Let's run agent_001 from the terminal: 
```bash
docker exec cosmos_core agent_001
```
and run agent_002 from another terminal window:
```bash
docker exec cosmos_core agent_002
```

Agents are able to discover and communicate with each other.

Let's also try running agent_cpu:
```bash
docker exec cosmos_core agent_cpu 
```

We can see what agents are running with the *agent* program, giving it the argument *list*
```bash
docker exec cosmos_core agent list 
```
<!--

1. [Installing COSMOS Core on Docker]({{site.baseurl}}/pages/2-getting_started/install/docker-install.html)
2. [Installing COSMOS Core on Linux]({{site.baseurl}}/pages/2-getting_started/install/ubuntu-install.html)
3. [Installing COSMOS Core on Windows]({{site.baseurl}}/pages/2-getting_started/install/ubuntu-install.html) (use [WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and follow the Linux Install instructions)
4. [Installing COSMOS Core on macOS](https://docs.google.com/document/d/146mBWBmxkAu0qBdSlCSer1nqVvOLBn_B-VzkcwpjhEU)
5. [Installing COSMOS Core on Raspberry Pi]({{site.baseurl}}/pages/4-tutorials/build/cross-compile.html)

After your are done installing COSMOS core you can [check your installation](https://hsfl.github.io/cosmos-docs/pages/2-getting_started/install/ubuntu-install.html#testing-cosmos-core).
-->



