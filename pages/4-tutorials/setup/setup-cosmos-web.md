---
title: "Getting Started Part 3 - COSMOS Web"
layout: series
permalink: /pages/4-tutorials/setup/cosmos-web.html

tags: [software]
keywords: software
sidebar: home_sidebar
toc: false

series:
  prev: /pages/4-tutorials/setup/development-environment.html
---

<div id="toc"></div>

## Introduction

The following is a usage guide for using the COSMOS Web interface.

## Pages

### Homepage

The homepage contains general information about the functionality of COSMOS Web and what the purpose of the website is.

### COSMOS Executive Operator (CEO)

The COSMOS Executive Operator shows the various nodes around the network and offers a high level overview of each node.

### Satellites & Ground Stations

These pages provide a detailed dashboard view of a certain satellite or ground station. They provide telemetry data in charts, plaintext, or visualizations. Users can also issue certain commands similar to how one would execute commands using the command line.
 
### Dashboard Manager
This is the page where users can configure local layouts (per computer) and add components to their liking.

## CEO
Each node on the network with agent_cpu running will be displayed here. If it is running, it displays its node name, IP address, and load in a card.

A node displayed on the CEO page.

## Satellites & Ground Stations
These pages are configurable dashboards and provide an overview of each system through various visualization components, such as through plaintext, 3D models, and charts. For example, the satellite might have components displaying the instantaneous CPU load:

The current CPU load and GiB information of neutron1’s onboard computer.
 
As mentioned before, these pages are a collection of components that can be configured by users to their liking, from how the components are laid out and sized to what is displayed on the component.


### Layout Selection

The Layout Selection component allows you to change between defined layouts, either system or user defined. The system defined layouts are the defaults.

- **Route Default**: Defined for all layouts in /satellite or /gs
- **Page Default**: Defined for /satellite/[page] or /gs/[page]
- **Page Default Simple**: Defined for /satellite/[page] or /gs/[page], but only contains essential components

### Socket Status

Displays whether Agent Mongo is properly connected or not. If connected, it will say “Socket is connected and operational.” Otherwise, it will say “No connection available. Attempting to reconnect.”

### Agent List

This component displays all of the running agents formatted as &lt;node>:&lt;process> on the network, along with the modified Julian date that it last pinged.

### Display Value

The display value component allows the display of instantaneous values from agents. You can specify the name of the value and it will display the corresponding value and date that it was last updated. It will display “-” in the value and date columns if no values have been received.

#### Settings

To customize the component, click the cog in the top right.

Global Settings:
- Name: Title displayed at top of component
Individual Settings:

- **Name**: Label for the value you want to display.
- **Node Process**: Formatted as &lt;node>:&lt;process>. Specifies the node process to extract the data key.
- **Data Key**: Namespace value to display.
- **Process Data Key**: JavaScript function body that processes the data key value (e.g. convert °C to °F).
- **Unit**: The unit label for the data key.
You can add additional values by using the bottom “Add Value” collapsible.
 
### Commands

With the command component, you can send agent command line commands as if you were in a terminal. 

On the top, you can set what &lt;node>:&lt;process> you want to select, and it will query the possible commands, which will then be displayed in the dropdown menu on the bottom left. 

The dropdown menu functions as a quick select and auto completion tool; simply select the command that you want and it will run it with any arguments that you choose to pass in the input to the right of it. 

If you wish to send regular commands without using any autocompleted commands, simply select the “➜ agent” option (the first one).

Other command tabs (i.e. in Ground Station KCC) have pre-set commands that can be executed by clicking on the appropriate buttons.


### Orbit

The orbit component displays the current XYZ location of the satellite in the form of a visualization and table.

Settings
Global Settings:
Name: Title displayed at top of component
Individual Settings:
Historical Date Range: Select a range of dates to display data from the database on the chart after pressing the “Show” button.
NOTE: The “Live” button on the top right must be off.
Name: Name of the satellite for a particular orbit.
Node Process: Specify the node process to source the orbital data from.
You can add additional values by using the bottom “Add Value” collapsible.

### Attitude

The attitude component displays the current quaternion orientation of the satellite.

### Charts

The chart component allows you to plot values over time. For example, you can plot the CPU load over time.

You must specify which &lt;node>:&lt;process> and key you would like to listen to in order to plot it. These can be modified via the settings for this component.

Download CSV
You can download the currently displayed values in CSV format by clicking the    button on the top right corner.
Toggle Value View
You can toggle whether the value on the chart is viewable or not.

Chart Features
Features in order:

- Download chart as a png image
- Zoom/Pan
- Zoom In/Zoom Out/Autoscale
- Reset Axes
- Toggle spike lines
- Show closest data on hover/Compare data on hover
- Settings

Global Settings:
- Chart Name: Title displayed at top of component.
- Data Limit: Limit the amount of values allowed to be displayed on the chart at a time (for all values).
- X Data Key: Name of the namespace value to display on the x axis.
- Process X Data Key: Provide function to modify the X Data Key
- Y Range: Min/max values to display on the y-axis (need to pan or zoom out to exit real-time first).
- X Range: Min/max values to display on the x-axis (need to pan or zoom out to exit real-time first).

Individual Settings:
- Historical Date Range: Select a range of dates to display data from the database on the chart after pressing the “Show” button.
  - NOTE: The “Live” button on the top right must be off.
- Name: Name of the data key on legend.
- Chart Type: Type of chart to be displayed (i.e. scatter, histogram).
- Chart Mode (optional): Changes how data points are displayed. Default is a dot
- Node Process: Identifies the &lt;node>:&lt;process> to be tracked.
- Y Data Key: Identifies the namespace to be plotted.
- Process Y Data Key: Allows the users to modify the data values via JavaScript coding.
- Marker Color: Color of the graph for the data.

### Macros

The user can select macros commands here and update them.

### Sequence

In this component, the user can execute pre-designed sequences of commands with a single button push. The command sequence can be seen by clicking on the ? next to the button.

### Set Values

The set values component allows the user to turn on or off the doppler and set various values for ground station properties that can be selected using the dropdowns. 

### Radio

The radio component shows the files and the progress of uplinking them.

### Activity

The activity component displays any current or upcoming events for the respective satellite or ground station.

