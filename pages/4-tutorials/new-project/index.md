---
title: Start a New COSMOS Project
permalink: /pages/4-tutorials/new-project/index.html
layout: page
index: 4.4
tags: [software]
keywords: software
---

In this tutorial we’ll demonstrate how to create new projects within the COSMOS framework. We will use the project name **“myproject”**.

## 4.4.1 Create a new Git Repository
Go to [Bitbucket](https://bitbucket.org/), [GitHub](https://github.com/) or GitLab to create a new git repository for your new project “myproject” (instructions to [create a new repo in Bitbucket](https://confluence.atlassian.com/bitbucket/create-a-git-repository-759857290.html), instructions to [create a new repo in GitHub](https://help.github.com/articles/create-a-repo/)). Don’t forget to create a “README.md” file that describes the project.

## 4.4.2 Clone Git Repository
Clone the repository to `~/cosmos/source/projects/myproject`

## 4.4.3 Copy Template Project
The easiest way to bootstrap a new COSMOS project is to use the template (otherwise you’ll have to create a few things from scratch).  Clone the template repository from https://github.com/hsfl/cosmos-project-template to the projects folder (`cosmos/source/projects/`). You can also check other examples from the COSMOS projects list.
Copy the files from the template folder into “my-project” folder.
For example: copy from `cosmos/source/projects/project-template` to `cosmos/source/projects/my-project`.
## 4.4.4 Hello World Test
Create a `hello_world.cpp` test program using Qt Creator.

1. Open Qt Creator
2. Open the file `CMakeLists.txt`.  
- *File → Open File or Project ...*
- Open the `CMakeLists.txt` file `cosmos/source/projects/my-project/source/CMakeLists.txt`
3. Select “configure project” when the window opens.
4. Create the new file
- *File → New File or Project → C++ Source file*
- Add the new file into `cosmos/source/projects/my-project/source/tests/hello_world.cpp`
5. In Qt Creator, edit the `CMakeLists.txt` and enter the following line:
```
add_executable(hello_world "hello_world.cpp")
```
6. Build
Build by clicking on the hammer icon or with the shortcut <kbd>CTRL</kbd> + <kbd>B</kbd>
6. Run
Run the program in Qt with the shortcut <kbd>CTRL</kbd> + <kbd>R</kbd>
