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

### COSMOS Web Dependencies

- Any OS that supports Node.js
- [Node.js](https://nodejs.org/en/download/)
  - A runtime environment that supports JavaScript

### Agent MongoDB Dependencies

- Ubuntu 18.04
- [MongoDB Server](https://docs.mongodb.com/manual/administration/install-community/)
  - A non-relational database.

### Install OpenSSL & Boost WebSocket Library Packages

These packages allow us to use WebSockets for Agent Mongo.

```bash
$ sudo apt-get update
$ sudo apt-get install build-essential wget libz-dev gcc-7 g++-7 cmake git openssl libssl-dev libsasl2-dev libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev -y
```

### Install MongoDB C Driver
The MongoDB C Driver allows us to interface with a MongoDB server in C.
Run the following commands in a terminal:

```bash
$ wget
https://github.com/mongodb/mongo-c-driver/releases/download/1.17.0/mongo-c-driver-1.17.0.tar.gz
$ tar xzf mongo-c-driver-1.17.0.tar.gz
$ cd mongo-c-driver-1.17.0
$ mkdir cmake-build
$ cd cmake-build

$ cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
$ make -j4
$ sudo make install
```

### Install MongoDB C++ Driver

The MongoDB C++ Driver allows us to interface with a MongoDB server in C++.
Run the following commands in a terminal:

```bash
$ git clone https://github.com/mongodb/mongo-cxx-driver.git --branch releases/stable --depth 1
$ cd mongo-cxx-driver/build

$ cmake -DCMAKE_BUILD_TYPE=Release -DBSONCXX_POLY_USE_BOOST=1 -DCMAKE_INSTALL_PREFIX=/usr/local ..
$ make -j4
$ sudo make install
```

### Check that you have GCC/G++ 7.4+ installed

```bash
$ gcc --version
$ g++ --version
```

### Change compiler to GCC/G++ 7.4+ if it is not your default compiler

If, by default, you do not have GCC/G++ 7.4+, you must retrieve the compiler and change it to your default. Otherwise, you can skip this step.

```bash
$ sudo apt-get install -y software-properties-common
$ sudo add-apt-repository ppa:ubuntu-toolchain-r/test
$ sudo apt update
$ sudo apt install g++-7 -y
$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 60 --slave /usr/bin/g++ g++ /usr/bin/g++-7
$ sudo update-alternatives --config gcc
```

## Installing COSMOS Web & Agent Mongo

### COSMOS Web Installation

Clone the COSMOS Web git repository to retrieve the source code and set it up.

```bash
$ git clone https://github.com/hsfl/cosmos-web.git ~/cosmos/source/tools/cosmos-web
$ cd ~/cosmos/source/tools/cosmos-web
$ npm install
$ cp .env.defaults .env
```

Set up environment variables by editing the .env file. These are settings for your local copy of COSMOS Web based on your set up. The pre-set values are defaults and can be changed.

```bash
API_IP=localhost # IP of agent_mongo
WEBSOCKET_PORT=8081 # IP of websocket port on agent_mongo
REST_PORT=8082 # IP of REST port on agent_mongo
CESIUM_ION_TOKEN= # Token for the globe simulation (optional). Get a token here -> https://cesium.com/ion/signup?gs=true
COSMOS_BIN=~/cosmos/bin # Location of your COSMOS bin folder
MONGODB_COLLECTION=dump # The collection you are storing COSMOS data in
```

###  Agent MongoDB Installation

Clone the COSMOS Web git repository to retrieve the source code and set it up.

```bash
$ git clone https://github.com/spjy/cosmos-mongodb.git ~/cosmos/source/tools/cosmos-mongodb
$ cd ~/cosmos/source/tools/cosmos-mongodb

$ mkdir build
$ cd build

$ cmake ../source
$ make
```

## Running

We are now ready to run COSMOS Web and Agent MongoDB!

### Running COSMOS Web

Navigate to the root directory of COSMOS Web. Then, to start an instance of COSMOS Web, open a terminal and run:

```
$ cd ~/cosmos/source/tools/cosmos-web
$ npm start
```

In a web browser, connect to http://0.0.0.0:5000 to access it.


### Running Agent MongoDB

Navigate to the output folder of Agent Mongo, then run the agent_mongo executable. Be sure to set the appropriate command line arguments if the defaults deviate from your environment.

$ cd ~/cosmos/tools
$ ./agent_mongo

### Agent Mongo Command Line Arguments

| Argument               | Default Value                         | Description                                               |
|------------------------|---------------------------------------|-----------------------------------------------------------|
| --include              |                                       | Nodes to listen to on the COSMOS network                  |
| --exclude              |                                       | Nodes to not listen to on the COSMOS network              |
| --whitelist_file_path |                                       | JSON file that contains nodes to include/exclude          |
| --database             | db                                    | Name of database to use in MongoDB                        |
| --file_walk_path       | get_cosmosnodes(true) (Core function) | Path to the COSMOS nodes folder                           |
| --agent_path           | ~/cosmos/bin/agent                    | Location of the agent executable                          |
| -- shell               | /bin/bash                             | Location of the shell you want to use to execute commands |
| --mongo_server         | mongodb://localhost:27017/            | MongoDB server IP                                         |

### Confirm COSMOS Web and Agent MongoDB connection

In a satellite or ground station page (e.g. http://0.0.0.0:5000/satellite/neutron1), in the top toolbar, it should say “Connected”.

Now you are done and ready to use and configure COSMOS Web!
