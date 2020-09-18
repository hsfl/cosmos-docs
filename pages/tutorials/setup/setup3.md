---
title: "Getting Started Part 3 - COSMOS Web"
layout: series
permalink: /pages/tutorials/setup/setup3.html

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
  prev: /pages/tutorials/setup/setup2.html
  next: /pages/tutorials/setup/setup4.html
---

<div id="toc"></div>

## What You Need
* The assembled cubesat (included)
* A computer with the Ubuntu development environment installed
* USB Type A to USB Micro B cable

### 1. Connect to the BeagleBone
Using the USB Type A to USB Type B mini cable, connect the port labeled `USB` on the BeagleBone to your computer. This will power and boot the BeagleBone.

Open a web browser inside of Ubuntu and enter `192.168.6.2` into the URL bar. It may take a little while to connect at first, especially if the BeagleBone has not finished booting.

After a while you should see the Cloud9 IDE appear in your browser.

{% include note.html content='On Windows hosts you may need to eject the BeagleBone device from File Explorer first.' %}

{% include image.html file="/resources/tutorials/setup/part3/cloud9.png" width="100%" %}
<br>

The COSMOS agents (flight software programs) running on the BeagleBone should automatically start.

### 2. Start COSMOS Web
In an Ubuntu terminal (_not_ the BeagleBone terminal), enter the following commands:

```bash
$ sudo systemctl start mongod
$ ~/cosmos/tools/agent_mongo
```

Open another terminal and enter the following commands:

```bash
$ cd ~/cosmos/source/tools/cosmos-web
$ npm start
```
Your browser should automatically open to a new page and load the COSMOS Web GUI.

{% include note.html content="If the page doesn't open, try entering <code>0.0.0.0:5000</code> in a new browser tab." %}


{% include image.html file="/resources/tutorials/setup/part3/cosmos_web_home.png" width="100%" alt="COSMOS Web homepage" align="center" %}

Next, click on _Realms_ -> _Artemis_ to switch to the Artemis cubesat view. In the box at the top left you will see a list of agents that are currently running on the BeagleBone.


{% include note.html content="if you don't see any agents other than `agent_mongo`, then you will need to start them manually by running the following command in a terminal window in the Cloud9 IDE:
`./start_agents`" %}

{% include image.html file="/resources/tutorials/setup/part3/cosmos_web_route.png" width="100%" alt="COSMOS Web route" align="center" %}
