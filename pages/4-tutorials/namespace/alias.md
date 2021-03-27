---
title: COSMOS Aliases
permalink: /pages/4-tutorials/namespace/alias.html
layout: series
index: 4.6.5
tags: [software]
keywords: software
series:
    language: "C++"
    prev: /pages/4-tutorials/namespace/new-device.html
---

## Introduction

COSMOS aliases are an extension of the COSMOS Namespace that allows the mapping of a new user defined name to any existing Name, or Equation, in the Namespace. These can be used for such things as providing more user friendly names, or mapping an external Namespace into COSMOS. The following example shows a typical use of COSMOS aliases. There is a self contained example that can be run using Qt creator from the folder cosmos/source/core/tutorials/namespace/aliases and using the file alias.cpp.
In addition to adding aliases through a program, aliases can also be added to a node via the `aliases.ini` file. These are specified in the format below: an aliases name, a space, the equation, and a newline to begin a new alias. Note that each operation is enclosed by parentheses. An example is given below.
```
busPowerOn (“device_bus_power_003”=1)
busPowerConstant 102
busPowerExample ((((“device_bus_power_003”*2)+(“device_bus_power_002”*2))=16)&(“device_bus_power_003”=4))
```
*Direct COSMOS namespace aliases, e.g. `busPower “device_bus_power_003”` are currently not working. Each alias must either be a constant or an equation. You can get around this by defining these aliases as ‘equations’ of your alias multiplied by 1, e.g. `busPower (“device_bus_power_003”*1.0)`.

## Example

### Objective
Convert the IMU temperature data from degrees Celsius to Kelvin. This actually could be handled differently by unit conversion but the purpose here is to demonstrate the use of equations in COSMOS.

The base unit in COSMOS for temperature is Kelvin so let’s define the equation to convert to from Kelvin to Celsius:
`
C = K - 273.15
`
The namespace variable for the imu temperature in this case, is "device_imu_temp_000". Knowing this, we can add the equation to namespace. The equation will be formed as a JSON string
`(\"device_imu_temp_000\" - 273.15)`


To simplify the use of this equation we use an alias such as
"imuTempCelcius"

The code for creating an alias would be as follows: 

```
string equation = "(\"device_imu_temp_000\" - 273.15)";
jsonhandle eqhandle; 
json_equation_map(equation, cinfo, &eqhandle); 
string alias = "imuTempCelcius";
json_addentry(alias, equation, cinfo); 
```
