---
title: COSMOS Namespace
permalink: /pages/4-tutorials/namespace/index.html
layout: series
index: 4.6.1
tags: [software]
keywords: software
series:
    language: "C++"
    next: /pages/4-tutorials/namespace/soh.html
---


The COSMOS namespace provides access to a large number of commonly used devices. For each of these devices, as for example the GPS gpsstruc, items are defined in an internal structure that represent the most commonly used values for this device. These internal values are then mapped to names in the COSMOS Namespace.

If some device is not in the COSMOS namespace then it can be added by extending the code and recompiling. However, one of the driving principles of COSMOS is to provide a generic environment that avoids the necessity of changing and/or recompiling the code to support something new. In the case where changes to the code are not desirable, or the amount of new information does not warrant changes, a telemstruc has been provided. This generic telemetry device allows the assignment of a single value of any type, which then can be accessed as the appropriate type through standard names in the namespace. For further flexibility, these internally defined names can be mapped to user friendly names through aliases.

The example code shows how to use a generic device so that new information can be added without much effort. Another approach would be to create or add the piece of information directly into the namespace. This approach, although encouraged, requires more work. Please see add new device.
The self contained example can be compiled and run using Qt creator from the folder cosmos/source/core/tutorials/namespace/generic-device. First open and compile the agent_generic_device_neighbour.pro file in Qt Creator (this will compile agent_generic_device_neighbour.cpp) then open agent_generic_device_test.pro also in Qt Creator (this will compile agent_generic_device_test.cpp).

If you would like to print all available namespaces
```
string sohtemp = json_list_of_all(agent->cinfo).c_str();
printf("Devices: %s\n", sohtemp.c_str());

```
SOH namespaces
```
Devices: {
  "node_name",
  "node_type",
  "node_state",
  "node_powgen",
  "node_powuse",
  "node_powchg",
  "node_battlev",
  "node_loc_bearth",
  "node_loc_pos_eci",
  "node_loc_att_icrf",
  "device_ssen_utc_000",
  "device_ssen_temp_000",
  "device_ssen_azimuth_000",
  "device_ssen_elevation_000",
  "device_ssen_qva_000",
  "device_ssen_qvb_000",
  "device_ssen_qvc_000",
  "device_ssen_qvd_000",
  "device_imu_utc_000",
  "device_imu_temp_000",
  "device_imu_accel_000",
  "device_imu_omega_000",
  "device_imu_alpha_000",
  "device_imu_mag_000",
  "device_imu_bdot_000",
  "device_gps_utc_000",
  "device_gps_temp_000",
  "device_gps_geocs_000",
  "device_gps_geocv_000",
  "device_gps_dgeocs_000",
  "device_gps_dgeocv_000",
  "device_gps_geods_000",
  "device_gps_geodv_000",
  "device_gps_dgeods_000",
  "device_gps_dgeodv_000",
  "device_gps_time_status_000",
  "device_gps_solution_status_000",
  "device_gps_position_type_000",
  "device_gps_sats_used_000",
  "device_pvstrg_utc_000",
  "device_pvstrg_temp_000",
  "device_pvstrg_power_000",
  "device_pvstrg_utc_001",
  "device_pvstrg_temp_001",
  "device_pvstrg_power_001",
  "device_pvstrg_utc_002",
  "device_pvstrg_temp_002",
  "device_pvstrg_power_002",
  "device_pvstrg_utc_003",
  "device_pvstrg_temp_003",
  "device_pvstrg_power_003",
  "device_pvstrg_utc_004",
  "device_pvstrg_temp_004",
  "device_pvstrg_power_004",
  "device_pvstrg_utc_005",
  "device_pvstrg_temp_005",
  "device_pvstrg_power_005",
  "device_tsen_utc_000",
  "device_tsen_temp_000",
  "device_tsen_utc_001",
  "device_tsen_temp_001",
  "device_tsen_utc_002",
  "device_tsen_temp_002",
  "device_tsen_utc_003",
  "device_tsen_temp_003",
  "device_tsen_utc_004",
  "device_tsen_temp_004",
  "device_tsen_utc_005",
  "device_tsen_temp_005",
  "device_tsen_utc_006",
  "device_tsen_temp_006",
  "device_tsen_utc_007",
  "device_tsen_temp_007",
  "device_tsen_utc_008",
  "device_tsen_temp_008",
  "device_tsen_utc_009",
  "device_tsen_temp_009",
  "device_tsen_utc_010",
  "device_tsen_temp_010",
  "device_tsen_utc_011",
  "device_tsen_temp_011",
  "device_tsen_utc_012",
  "device_tsen_temp_012",
  "device_tsen_utc_013",
  "device_tsen_temp_013"
}
```

To view if a specific entry is within the COSMOS namespace, search for the device within `core/libraries/support/jsonlib.cpp`. Devices are indexed by this entry, an underscore, and a three digit ID (e.g . 000, 001, 002, …).

A TeX document is available on `core/tutorials/namespace`, which details much of the motivation and background behind the namespace itself.
