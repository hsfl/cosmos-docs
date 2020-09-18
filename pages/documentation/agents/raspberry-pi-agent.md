---
title: Raspberry Pi Agent
permalink: /pages/documentation/agents/raspberry-pi-agent.html
layout: agent

tags: [software, raspberrypi]
keywords: software

agent_name: agent_raspi
---

## Description
The Raspberry Pi agent (aka `agent_raspi`) is an agent that handles communication with the Raspberry Pi, including startup, shutdown, and data transfer.

## Available Agent Data
Below is a table showing which properties are collected from various other agents. This data can be viewed through the [`get_data`](#get-agent-data) request.

(TODO)

<table>
    <thead>
        <tr>
            <th>Agent Program</th>
            <th>Device</th>
            <th>JSON Key</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=6>agent_temp</td>
            <td>N/A</td>
            <td>agent_temp.active</td>
            <td>Whether or not the agent can be reached</td>
        </tr>
        <tr>
            <td>EPS Temperature Sensor</td>
            <td>agent_temp.temp_eps</td>
            <td>Temperature of the EPS</td>
        </tr>
        <tr>
            <td>BeagleBone Temperature Sensor</td>
            <td>agent_temp.temp_obc</td>
            <td>Temperature of the BeagleBone</td>
        </tr>
        <tr>
            <td>Raspberry Pi Temperature Sensor</td>
            <td>agent_temp.temp_raspi</td>
            <td>Temperature of the Raspberry Pi</td>
        </tr>
        <tr>
            <td>Battery Temperature Sensor</td>
            <td>agent_temp.temp_battery</td>
            <td>Temperature of the batteries</td>
        </tr>
        <tr>
            <td>PyCubed Temperature Sensor</td>
            <td>agent_temp.temp_pycubed</td>
            <td>Temperature of the PyCubed</td>
        </tr>
        <tr>
            <td rowspan=7>agent_sun</td>
            <td>N/A</td>
            <td>agent_sun.active</td>
            <td>Whether or not the agent can be reached</td>
        </tr>
        <tr>
            <td>+X Sun Sensor</td>
            <td>agent_sun.ss_plusx</td>
            <td>Lux reading from the +X sun sensor</td>
        </tr>
        <tr>
            <td>-X Sun Sensor</td>
            <td>agent_sun.ss_minusx</td>
            <td>Lux reading from the -X sun sensor</td>
        </tr>
        <tr>
            <td>+Y Sun Sensor</td>
            <td>agent_sun.ss_plusy</td>
            <td>Lux reading from the +Y sun sensor</td>
        </tr>
        <tr>
            <td>-Y Sun Sensor</td>
            <td>agent_sun.ss_minusy</td>
            <td>Lux reading from the -Y sun sensor</td>
        </tr>
        <tr>
            <td>+Z Sun Sensor</td>
            <td>agent_sun.ss_plusz</td>
            <td>Lux reading from the +Z sun sensor</td>
        </tr>
        <tr>
            <td>-Z Sun Sensor</td>
            <td>agent_sun.ss_minusz</td>
            <td>Lux reading from the -Z sun sensor</td>
        </tr>
        <tr>
            <td rowspan=7>agent_pycubed</td>
            <td>N/A</td>
            <td>agent_pycubed.active</td>
            <td>Whether or not the agent can be reached</td>
        </tr>
        <tr>
            <td rowspan=3>IMU</td>
            <td>Acceleration</td>
            <td>agent_pycubed.imu.accel</td>
            <td>A vector containing acceleration readings</td>
        </tr>
        <tr>
            <td>Magnetic Field</td>
            <td>agent_pycubed.imu.mag</td>
            <td>A vector containing magnetic field readings</td>
        </tr>
        <tr>
            <td>Angular Acceleration</td>
            <td>agent_pycubed.imu.gyro</td>
            <td>A vector containing angular acceleration readings</td>
        </tr>
    </tbody>
</table>