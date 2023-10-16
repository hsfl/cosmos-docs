---
title: Install COSMOS Core on Docker
layout: series
permalink: /pages/2-getting_started/install/docker-install.html
index: 2.2
tags: [software]
keywords: software
sidebar: home_sidebar
toc: false
---


## Introduction

This tutorial will help you install the COSMOS core programs and libraries on a Docker container. 

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
