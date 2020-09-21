---
title: COSMOS Tutorial Part 1 - COSMOS and QtCreator
permalink: /pages/tutorials/cosmos/cosmos1.html
layout: series

tags: [software]
keywords: software
toc: false

series:
    language: "C++"
    next: /pages/tutorials/cosmos/cosmos2.html
---


> **_Note:_** Not using the Artemis Development Environment? Then you should first follow the instructions for
> [installing COSMOS from scratch]({{site.folder_tutorials_install}}/cosmos-from-scratch.html).


## Introduction
QtCreator is an IDE (integrated development environment) targeted at C/C++ developers, and is included in the [Artemis Development Environment]({{site.folder_docs_other}}/development-environment.html) by default.


## Create a New COSMOS Project

Open up the `~/cosmos/source/projects/` directory. This folder contains all COSMOS projects that you will write.

Duplicate the project folder `simpleagent_template` and rename it as you wish. In this tutorial, we will use the project name `my_project`.

{% include image.html file="/resources/tutorials/cosmos/part1/copy_template.png" %}

Open up QtCreator and go to _File_ -> _Open File or Project..._, and open the file `~/cosmos/source/projects/my_project/CMakeLists.txt`. This file contains the project configuration.

{% include image.html file="/resources/tutorials/cosmos/part1/open_project_window.png" %}


{% include important.html content="If this is your first time working with the project or you have
recently updated your software, you may be met with a `Configure Project` page.
Just select the `ARM32` kit and deselect the `Desktop` kit, then click the `Configure Project` button." %}

The project `simpleagent_template` will appear in the navigation pane on the left side of the window (you can always rename the project by editing the `CMakeLists.txt` file). Expand the project (double click), then expand the target `my_agent` and open the source file `my_agent.cpp`.

You should now see the `my_agent.cpp` source code in the editor.



{% include image.html file="/resources/tutorials/cosmos/part1/open_file.png" width="100%" %}
