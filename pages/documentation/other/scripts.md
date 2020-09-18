---
title: Development Environment
permalink: /pages/documentation/other/scripts.html
layout: page

keywords: software
---


## Brief

There are several shell scripts provided in the Artemis Cubesat Kit repository which take care of otherwise-tedious
operations. To run these scripts, you should first change the working directory of your terminal:

```bash
cd ~/artemis-cubesat-kit/scripts
```

## Utilities

### Launch Cloud9 IDE

Usage: `./cloud9`

Description:

This script launches the Cloud9 IDE in a new firefox tab.


### Launch COSMOS Web

Usage: `./cosmos-web [-s]`

Description:

This script runs the tools needed to operate COSMOS Web. If the `-s` flag is not present, the script will
run all of the tools in the same terminal window. If the `-s` flag is present, the script will open
a new terminal window for one of the processes.


## Deploying Software

### Deploy Agents

Usage: `./deploy-agents`

Description:

This script copies the agent executable files from `~/cosmos/source/projects/beaglebone/build-arm32/bin` to the
BeagleBone under the folder `~/agents`.

Internally this script uses the `rsync` command.

### Deploy Raspberry Pi Software

Usage: `./deploy-raspi`

Description:

This script copies the Raspberry Pi software from `~/software/RaspberryPi` to the Raspberry Pi under the folder
`~/rasberry-pi`.

Internally this script uses the `rsync` command to copy the folder to a temporary folder on the BeagleBone, then calls
`rsync` on the BeagleBone using `ssh` to copy the temporary folder to the Raspberry Pi.


## Updating Software

### Update Agents

Usage: `./update-agents`

This script overwrites the existing BeagleBone COSMOS project under `~/cosmos/source/projects/beaglebone` using the
latest software from the repository.

### Update Raspberry Pi Software

Usage: `./update-raspi`

This script overwrites the existing Raspberry Pi software under `~/software/RaspberryPi` using the
latest software from the repository.

### Update COSMOS Routes

Usage: `./update-routes`

This script overwrites the existing COSMOS Web routes using the latest software from the repository. You should call
this script if you are also using the `update-agents` script.


## Installation

{% include warning.html content="These scripts are meant for those not using the development environment,
and should not be called if you are using it!" %}

### Install COSMOS

Usage: `./install-cosmos`

Installs COSMOS, giving the option of switching to the 'dev' branch.

### Install COSMOS Web

Usage: `./install-cosmos-web`

Installs COSMOS Web and its dependencies.