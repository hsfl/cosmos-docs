---
title: Troubleshooting
permalink: /pages/8-help/troubleshooting.html
layout: page
index: 8.1

tags: [software]
keywords: software
---

Here are some of the problems/issues that we have found as well as our solutions for them. If you come across a problem that isn't listed, create an issue and provide us with information so that we can help to solve the problem.
## 1. Agent is shutting down
If you get this error
```
Shutting down Agent. Last error: DATA_ERROR_NODES_FOLDER
unable to start agent_exec (-366) DATA_ERROR_NODES_FOLDER
```
It may be that the Node folder might not exist. Try downloading/cloning the “CubeSat1” node from
https://github.com/hsfl/cosmos-node-cubesat1

Put this folder inside the “Nodes” folder and rename it to

## 2. Cannot Clone Repositories
If you are using the "git@github.com" urls, confirm that you are using a *SSH key* (Sourcetree runs "pageant SSH" to use SSH keys, it's icon should appear on the taskbar) that is linked to your Bitbucket account.
*To clone a repository without an SSH key* (this will allow you to get the code, but will not allow you to contribute to COSMOS. We recommend setting up a SSH to contribute to COSMOS) use the following urls:
| Where to Clone to      | URL                                                     |
|------------------------|---------------------------------------------------------|
| \cosmos\source\core    | https://bitbucket.org/cosmos-project/core.git           |
| \cosmos\nodes\cubesat1 | https://bitbucket.org/cosmos-project/nodes-cubesat1.git |
| \cosmos\resources      | https://bitbucket.org/cosmos-project/resources.git      |

## 3. Qt isn’t working
First check to see that your version of Qt isn't outdated. An older version of Qt may not be able to run the current build of COSMOS. Next, if you have the project opened already, go to Projects on the left-hand side, then click on "Manage Kits" on the top. Otherwise, go to Tools->Options (Or "Preferences" on Mac). Then click on "Build and Run" on the left side, then click on the "Kits" tab. Click on the option that currently has "(default)" appended to it, and scroll down. Check the C compiler, the C++ compiler, and CMake.

The rest can be found [here](https://docs.google.com/document/d/106AzCcbrtvSrXEH_f0JZ_TLWYKhtbVL9JIH8Dmy0eIY/edit#)
