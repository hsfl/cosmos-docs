---
title: "COSMOS Web Installation"
layout: series
permalink: /pages/2-getting_started/install/cosmos-web.html
index: 2.3

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false


series:
  prev: /pages/2-getting_started/install/ubuntu-install.html
---

## Introduction

COSMOS Web is a web application that allows the control and visualization of data incoming from the COSMOS ecosystem through a user interface.

Agent MongoDB is the server component of COSMOS Web and bridges the gap between COSMOS Web and the COSMOS ecosystem via WebSockets. It also handles data storage in a MongoDB database.

![cosmos web](https://user-images.githubusercontent.com/1541868/126595087-d598d736-b824-4e7b-bf6b-0c3f62f6ec17.PNG)


## Dependencies

{% include warning.html content="It is still _highly_ recommended that you install COSMOS Web on Ubuntu 18.04 for compatibility." %}

### COSMOS Web Dependencies

- Any OS that supports Node.js
- [Node.js](https://nodejs.org/en/download/)
  - A runtime environment that supports JavaScript
  - Install Node.js v7.5.3 (as of April 4/29/2021)
  - To install [node.js on WLS](https://docs.microsoft.com/en-us/windows/dev-environment/javascript/nodejs-on-wsl)

To update npm

```bash
npm install -g npm
```

### MongoDB Dependencies
- Ubuntu 18.04
- Install [MongoDB Server](https://docs.mongodb.com/manual/administration/install-community/) on a native Ubuntu computer distribution
- If you're using Ubuntu on WSL [MongoDB Server](https://docs.microsoft.com/en-us/windows/wsl/tutorials/wsl-database)

MongoDB is A non-relational database. COSMOS Web uses ...

## Installing COSMOS Web

### COSMOS Web Installation

Clone the COSMOS Web git repository to retrieve the source code and set it up.

```bash
$ git clone https://github.com/hsfl/cosmos-web.git ~/cosmos/source/tools/cosmos-web
$ cd ~/cosmos/source/tools/cosmos-web
$ npm install
$ cp .env.example .env
```

Set up environment variables by editing the .env file. These are settings for your local copy of COSMOS Web based on your set up. The pre-set values are defaults and can be changed. Don't forget to change the USER.

```bash
API_IP=localhost # IP of agent_mongo
WEBSOCKET_PORT=8081 # IP of websocket port on agent_mongo
REST_PORT=8082 # IP of REST port on agent_mongo
COSMOS_BIN=/home/<USER>/cosmos/bin # Location of your COSMOS bin folder
FLIGHT_MODE=false
```

### COSMOS Web API Installation
Clone the COSMOS Web API repository and set it up.
```bash
$ git clone https://github.com/hsfl/cosmos-webapi.git ~/cosmos/source/tools/cosmos-webapi
$ cd ~/cosmos/source/tools/cosmos-webapi

$ npm install 
$ cp .env.example .env
```

Set up environment variables by editing the .env file. Don't forget to change the USER.
```bash
DB_URI=mongodb://localhost:27017
WEBSOCKET_PORT=8081
API_PORT=8082
COSMOS_DIR=/home/<USER>/cosmos/
HOST_NODE= cubesat1 # node name  
```

## Running

We are now ready to run COSMOS Web and COSMOS Web API!

### Running COSMOS Web

Navigate to the root directory of COSMOS Web. Then, to start an instance of COSMOS Web, open a terminal and run:

```
$ cd ~/cosmos/source/tools/cosmos-web
$ npm start
```
In a web browser, connect to http://0.0.0.0:5000 to access it.

### Running COSMOS Web API
Navigate to the root directory of COSMOS WebApi, then open a terminal and run:
```bash
$ cd ~/cosmos/source/tools/cosmos-webapi
$ npm run dev
```

### Confirm COSMOS Web and API connection
In a satellite or ground station page (e.g. http://0.0.0.0:5000/realm/cubesat1), in the top toolbar, it should say “Connected”.
Now you are done and ready to use COSMOS Web!
