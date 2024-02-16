---
title: "Development Environment Setup Guide"
layout: series
index: 2.1
permalink: /pages/2-getting_started/development-environment.html

tags: [software]
keywords: software
sidebar: home_sidebar


series:
  next: /pages/2-getting_started/install/ubuntu-install.html
---
This is a guide on how to set up your Development Environment (DE) to compile, 
run, and debug COSMOS.

## Installing via Docker (Recommended)
We recommend installing COSMOS via Docker. By using Docker containers you will 
automatically resolve all the COSMOS dependencies.

### Step 1: Install Prerequisites
#### For Windows Users
For Windows users, install [Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/install)
first:
- Open the Start menu, type "PowerShell", then right-click PowerShell and 
select "Run as administrator". 

{% include image.html file="/resources/tutorials/setup/part2/powershell.png" width="100%" %}

- Confirm the User Account Control prompt.
- Type `wsl --install` into the window and press enter.

{% include image.html file="/resources/tutorials/setup/part2/wsl-install.png" width="100%" %}

- After the installation completes, restart your computer.
- After restarting, type "wsl" in the Start menu. It should bring up a penguin
icon. Run this command.
- A window should open, finishing the WSL installation. You will be prompted to
set a username and password for the Ubuntu installation. You can use any values 
you wish. This tutorial will use the username `localuser`.

{% include image.html file="/resources/tutorials/setup/part2/wsl-firstrun.png" width="100%" %}

- Restart your computer.
- After restarting, type "wsl" in the Start menu. It should bring up a penguin
icon. Run this command.

{% include image.html file="/resources/tutorials/setup/part2/wsl-run.png" width="100%" %}

- You can now "pin" the WSL icon on your toolbar to bring up an Ubuntu terminal.
Use this terminal window in order to run commands in the rest of this guide.

#### For all Operating Systems
Install [Docker Desktop](https://www.docker.com/get-started/). This program is a
graphical method to manage and run Docker containers. Note that you do *not* 
need a Docker account to use Docker Desktop.

Install [Visual Studio Code (VSCode)](https://code.visualstudio.com/). This is 
the preferred IDE for COSMOS development. This IDE can be extended by various 
extensions which make programming easier. 

Extensions can be searched for and installed from the Extensions tab on the left
navigation menu. Some recommended extensions for COSMOS development include:
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools):
Useful C/C++ features
- [C/C++ Themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes):
Better C/C++ Syntax Highlighting
- [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers):
Allows VSCode to connect to Docker containers
- [Doxygen Documentation Generator](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen):
Automatically generates Doxygen documentation templates
- [Code Spell Checker](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker):
Checks spelling in comments and code

### Step 2: Install Docker Container
Next, clone the COSMOS repository to your local machine. Run the following command in your terminal:
```
git clone https://github.com/hsfl/cosmos.git ~/cosmos-docker
```
After it completes, change to the `cosmos-docker` directory:
```
cd ~/cosmos-docker
```
Copy the `.env.example` file to `.env`. You don't need to change its contents:
```
cp .env.example .env
```
Now start the Docker container:
```
docker compose up -d
```
At this point, the container, containing the COSMOS installation, is running. 

{% include image.html file="/resources/tutorials/setup/part2/docker-install.png" width="100%" %}

You can verify that the container is running by running the command
```
docker ps
```
Alternatively, you can open Docker Desktop and see the running container.

{% include note.html content="If you get the error `Got permission denied while trying to connect to the Docker daemon...`, this is because your user has not been added to the `docker` group. Run the following command to add the current user to the `docker` group:
```
sudo usermod -aG docker $USER
```
Close and reopen the terminal window to continue. You can confirm that your user is within the `docker` group by running the command
```
groups
```
" %}