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

To update npm run this command on the command terminal:

```bash
sudo apt install npm
```

### MongoDB Dependencies
- Ubuntu 18.04
- Install [MongoDB Server](https://docs.mongodb.com/manual/administration/install-community/) on a native Ubuntu computer distribution
- If you're using Ubuntu on WSL install using these instructions [MongoDB Server](https://docs.microsoft.com/en-us/windows/wsl/tutorials/wsl-database)

MongoDB is A non-relational database. COSMOS Web uses ...

## Installing COSMOS Web

### COSMOS Web Installation

Clone the COSMOS Web git repository to retrieve the source code and set it up.

```bash
git clone https://github.com/hsfl/cosmos-web.git ~/cosmos/source/tools/cosmos-web
```
Change directory to the new cosmos-web folder:
```bash
cd ~/cosmos/source/tools/cosmos-web
```
Install the node.js dependencies
```bash
npm install
```
Copy the .env.example file to .env to set your own configuration
```bash
cp .env.example .env
```


Set up environment variables by editing the .env file. These are settings for your local copy of COSMOS Web based on your set up. The pre-set values are defaults and can be changed. Don't forget to change the USER.

```bash
API_IP=localhost # IP of cosmos web instance 
WEBSOCKET_PORT=8081 # IP of websocket port on agent_mongo
REST_PORT=8082 # IP of REST port on agent_mongo
COSMOS_BIN=/home/<USER>/cosmos/bin # Location of your COSMOS bin folder
FLIGHT_MODE=false
```

### COSMOS Web API Installation
Clone the COSMOS Web API repository and set it up.
```bash
git clone https://github.com/hsfl/cosmos-webapi.git ~/cosmos/source/tools/cosmos-webapi
```
Change directory to the new cosmos-webapi folder:
```bash
cd ~/cosmos/source/tools/cosmos-webapi
```
Install the node.js dependencies
```bash
npm install 
```
Copy the .env.example file to .env to set your own configuration
```bash
cp .env.example .env
```

Set up environment variables by editing the .env file. Don't forget to change the USER.
```bash
DB_URI=mongodb://localhost:27017
WEBSOCKET_PORT=8081
API_PORT=8082
COSMOS_DIR=/home/<USER>/cosmos/
HOST_NODE=cubesat1 # node name  
```

## Running

We are now ready to run COSMOS Web and COSMOS Web API!

### Running COSMOS Web

Navigate to the root directory of COSMOS Web. Then, to start an instance of COSMOS Web, open a terminal and run:

```
cd ~/cosmos/source/tools/cosmos-web
npm start
```
In a web browser, connect to http://localhost:5000 to access it.

![cosmos web](https://user-images.githubusercontent.com/1541868/126856185-2030eaf6-5114-4ce9-9a4e-6b4372226de3.PNG)


### Running COSMOS Web API
Navigate to the root directory of COSMOS WebApi, then open a terminal and run:
```bash
cd ~/cosmos/source/tools/cosmos-webapi
npm run dev
```

### Confirm COSMOS Web and API connection
In a satellite or ground station page (e.g. http://localuser:5000/realm/cubesat1), in the top toolbar, it should say “Connected”.
Now you are done and ready to use COSMOS Web!

### Display Data on COSMOS Web

Run Agent CPU on cubesat1 node
```
agent_cpu cubesat1
```

Navigate to the COSMOS Web page -> Realm -> CubeSat1. You should see the agent list populated with Agent CPU.

Run a simple orbital propagator to display the orbit
```
propagator_simple
```

## Docker Development Image (Optional)

Docker is a quick way to get started with running applications with ease.

### Self Build

If you want to run the COSMOS Web development image through Docker:

```
cd /path/to/cosmos-web
docker build . -t cosmos_web
docker run 3000:3000 cosmos_web
```

### Pulling Built Image

```bash
docker pull spencerpjy/cosmos-web
docker run 3000:3000 cosmos-web
```

# Using COSMOS Web

## Standards

### Filesystem

**File Naming Standards**

All files should be in upper camel case format. If it contains JSX within the file, the extension shall be `.jsx`.

**JSX File Standards**

All JSX files shall follow the React Hooks API standard. This means all components should follow the functional style component creation.

If a component requires a prop function to be passed (e.g. onChange), it should be abstracted out, meaning it should have its own function definition. If it is only changing the state and/or calling another function, you may use just an inline function. Function names should be in lower camel case.

The React component along with all React states, functions and props should be documented using the [React Styleguidist](https://react-styleguidist.js.org/docs/documenting.html) standard.

For use of a global state (to allow components to share the same state where the React state becomes difficult to manage), the React Context API should be used in conjunction with reducers (if needed).

**Folder Organization**

`/src/components`

This folder contains each page's components, and each page's corresponding components should be in a folder with the same name as the page.

Exception: Components that are reusable and can span across different pages are to be put into the `Global` folder.

`/src/pages`

This folder contains a different route to a page. Each page should contain only layout logic and store logic if children components require it.

`/src/store`

This folder contains the React Context global store and reducer logic.

### Commit Style

Follow the [AngularJS commit style](https://github.com/angular/angular/blob/master/CONTRIBUTING.md#-commit-message-guidelines).


# Developer Configurations

## Configuring Routes

You can configure the routes through `/src/routes/index.js`. Each top level object within the routes array corresponds to a page.

Each object has a `name`, `icon`, `component`, `path` and `props`. 

Name is the name that will show up on the navigation bar, the icon is the icon that will show up on the navigation bar, and the component is the component that will be shown on the route. 

The path is the route that corresponds to the page. You can add `/:id` at the end to specify that it is layout enabled. Props are optional; within the props object, you can provide the default layout of the page.

For the path

For example:

```javascript
const routes = [
  {
    name: 'Satellites',
    icon: 'rocket',
    path: '/satellite/:id',
    component: Dashboard,
    props: {
      defaultLayout: {
        lg: [
          {
            i: 'satellite-default-f',
            x: 6,
            y: 2,
            w: 6,
            h: 21,
            component: {
              name: 'Attitude',
              props: {
                attitudes: [
                  {
                    name: 'n1',
                    nodeProcess: 'cubesat1:propagator_simple',
                    quaternions: {
                      d: {
                        x: 0,
                        y: 0,
                        z: 0,
                      },
                      w: 0,
                    },
                    live: true,
                  },
                ],
              },
            },
          },
        ]
      }
    }
  }
]
```

## General Components

### AsyncComponent.jsx

AsyncComponent is the component that brings together dashboard components. It allows the dashboard components to be rendered via the `routes.js` file by name.

### BaseComponent.jsx 

BaseComponent is the component that contains common functionality and user interfaces across other components. For instance, it contains a header, configuration form modal, and content area for other componenents.

### ComponentSettings.jsx

ComponentSettings contains the configuration form modal used in BaseComponent.

### LayoutManager.jsx

LayoutManager is page that allows users to create layouts and add them to pages.

### LayoutSelector.jsx

LayoutSelector is the dropdown menu located at the top of layout enabled pages, and it allows selection of a certain layout for a certain page. 

## Other Components

See [this page](https://github.com/spjy/cosmos-web/blob/master/components.md).

# Application Usage

## Home Page

The splash page with a little bit of information.

## Dashboard Manager

The page to manage saved page layouts for routes such as satellites or ground stations.

### Modifying a Pre-existing Layout

On this page, there is a table to view the currently saved layouts on the computer. Modify it by clicking the `+` on the left or delete it using the `X` on the right.

### Creating a New Layout

To create a new layout, use the form below and fill out:

#### Route

The routes that are able to have saved layouts. For instance, you can select the layout to be saved under 'Ground Stations' or 'Satellites'.

#### Dashboard Name

The name of the layout for a certain route. Differentiate between other layout names.

#### Layout Array

*Sizing*. Each row has a width (w) of twelve (12).

*Formatting*. You must enter an array of objects. Each object contains a unique:

- Unique key (i) - to avoid conflicts with other layouts,  use the format: dashboardName-key
- Width (w)
- Height (h)
- Horiztonal position (w)
- Vertical position (y)
- Component name (component.name)
- Component props (component.props)

*Example*.
```json
[
  {
    "i": "dashboardName-a",
    "x": 0,
    "y": 0,
    "w": 6,
    "h": 7,
    "component": {
      "name": "Status",
      "props": {
        "name": "Ok"
      }
    }
  },
  {
    "i": "dashboardName-b",
    "x": 6,
    "y": 0,
    "w": 6,
    "h": 7,
    "component": {
      "name": "DisplayValues",
      "props": [
        {
          "name": "CPU Load",
          "nodeProcess": "beagle1:cpu",
          "dataKey": "device_cpu_load_000",
          "unit": "%",
        }
      ]
    }
  },
]
```

*Component Name and Props*: For a list of components that are available to be used and each component's props, see [components.md](https://github.com/spjy/cosmos-web/blob/master/components.md).

Click *Preview* to see the layout.

Click *Save Layout* to save it.

### Switching Layouts

On top of each Dashboard page, e.g. Sattelites or Ground Stations, a dropdown menu coupled with a button exist to allow for quickly switching between pre-defined layouts.
