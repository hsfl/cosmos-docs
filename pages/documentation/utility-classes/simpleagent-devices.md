---
title: SimpleAgent Devices
permalink: /pages/documentation/utility-classes/simpleagent-devices.html
layout: class

tags: [software]
keywords: software

class_name: device
list_members: false
---

> **_Note:_**  this wiki page only includes important features of the Device class. For the full documentation, see [Doxygen Documentation]({{site.folder_docs_other}}/doxygen.html).


## Description <a name="description"></a>
The `Device` class is a base (i.e. parent or super) class of various types. The devices have various properties which can be posted, meaning that they can be viewed externally (e.g. through a terminal or [[COSMOS Web]]). If a device doesn't have the properties necessary, custom properties can be used instead, although they cannot be posted. And if there isn't a supported device you need, you can always use the [`CustomDevice`](#customdevice) device type to hold custom properties (again, these cannot be posted).


{% include class_docs/members_table.html %}

## Supported Device Types
Below are the supported device types. Note that in the last column of each table, the `XXX` indicates the COSMSOS device number.

All of these devices below can accept custom properties, although these properties cannot be posted (i.e. viewed externally).

### TemperatureSensor
The `TemperatureSensor` device corresponds to a temperature sensor. In the Artemis CubeSat, the [ADT7311](https://www.analog.com/media/en/technical-documentation/data-sheets/ADT7311.pdf) is used.

| Supported Properties | Member Name   | Storage Type       | COSMOS Name                |
| -------------------- | ------------- | ------------------ | -------------------------- |
| UTC Timestamp        | `utc`         | `double` or `Time` | `device_tsen_utc_XXX`      |
| Temperature          | `temperature` | `float`            | `device_tsen_temp_XXX`     |
| Voltage              | `voltage`     | `float`            | `device_tsen_volt_XXX`     |
| Current              | `current`     | `float`            | `device_tsen_amp_XXX`      |
| Power                | `power`       | `float`            | `device_tsen_power_XXX`    |
| Enabled              | `enabled`     | `bool`             | `device_tsen_enabled_XXX`  |

### SunSensor
The `SunSensor` device corresponds to a sun sensor. In the Artemis CubeSat, the [OPT3001](https://www.ti.com/lit/ds/symlink/opt3001.pdf?HQS=TI-null-null-digikeymode-df-pf-null-wwe&ts=1591292821916) is used.

| Supported Properties | Member Name   | Storage Type       | COSMOS Name                |
| -------------------- | ------------- | ------------------ | -------------------------- |
| UTC Timestamp        | `utc`         | `double` or `Time` | `device_ssen_utc_XXX`      |
| Temperature          | `temperature` | `float`            | `device_ssen_temp_XXX`     |
| Voltage              | `voltage`     | `float`            | `device_ssen_volt_XXX`     |
| Current              | `current`     | `float`            | `device_ssen_amp_XXX`      |
| Power                | `power`       | `float`            | `device_ssen_power_XXX`    |
| Enabled              | `enabled`     | `bool`             | `device_ssen_enabled_XXX`  |

### Heater
The `Heater` device corresponds to a heater.

| Supported Properties | Member Name   | Storage Type       | COSMOS Name              |
| -------------------- | ------------- | ------------------ | ------------------------ |
| UTC Timestamp        | `utc`         | `double` or `Time` | `device_htr_utc_XXX`     |
| Temperature          | `temperature` | `float`            | `device_htr_temp_XXX`    |
| Voltage              | `voltage`     | `float`            | `device_htr_volt_XXX`    |
| Current              | `current`     | `float`            | `device_htr_amp_XXX`     |
| Power                | `power`       | `float`            | `device_htr_power_XXX`   |
| Enabled              | `enabled`     | `bool`             | `device_htr_enabled_XXX` |

### IMU
The `IMU` device corresponds to an IMU (inertial measurement unit). In the Artemis CubeSat, the [BMX160](https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BMX160-DS000.pdf) is used.

| Supported Properties | Member Name            | Storage Type       | COSMOS Name              |
| -------------------- | ---------------------- | ------------------ | ------------------------ |
| UTC Timestamp        | `utc`                  | `double` or `Time` | `device_imu_utc_XXX`     |
| Temperature          | `temperature`          | `float`            | `device_imu_temp_XXX`    |
| Voltage              | `voltage`              | `float`            | `device_imu_volt_XXX`    |
| Current              | `current`              | `float`            | `device_imu_amp_XXX`     |
| Power                | `power`                | `float`            | `device_imu_power_XXX`   |
| Enabled              | `enabled`              | `bool`             | `device_imu_enabled_XXX` |
| Magnetic Field       | `magnetic_field`       | `Vec3`             | `device_imu_mag_XXX`     |
| Linear Acceleration  | `acceleration`         | `Vec3`             | `device_imu_accel_XXX`   |
| Angular Acceleration | `angular_acceleration` | `Vec3`             | `device_imu_omega_XXX`   |

### GPS
The `GPS` device corresponds to a GPS (global positioning system).

| Supported Properties        | Member Name       | Storage Type       | COSMOS Name                |
| --------------------------- | ----------------- | ------------------ | -------------------------- |
| UTC Timestamp               | `utc`             | `double` or `Time` | `device_gps_utc_XXX`       |
| Temperature                 | `temperature`     | `float`            | `device_gps_temp_XXX`      |
| Voltage                     | `voltage`         | `float`            | `device_gps_volt_XXX`      |
| Current                     | `current`         | `float`            | `device_gps_amp_XXX`       |
| Power                       | `power`           | `float`            | `device_gps_power_XXX`     |
| Enabled                     | `enabled`         | `bool`             | `device_gps_enabled_XXX`   |
| Satellites Used             | `satellites_used` | `int`              | `device_gps_sats_used_XXX` |
| Latitude/Longitude/Altitude | `location`        | `Location`         | `device_gps_geods_XXX`     |
| Velocity                    | `velocity`        | `Vec3`             | `device_gps_geocv_XXX`     |

### Battery
The `Battery` device corresponds to a battery. In the Artemis CubeSat, the [LG MJ1 18650](https://www.18650batterystore.com/v/files/lg_mj1_data_sheet.pdf) is used.

| Supported Properties | Member Name      | Storage Type       | COSMOS Name                      |
| -------------------- | ---------------- | ------------------ | -------------------------------- |
| UTC Timestamp        | `utc`            | `double` or `Time` | `device_batt_utc_XXX`            |
| Temperature          | `temperature`    | `float`            | `device_batt_temp_XXX`           |
| Voltage              | `voltage`        | `float`            | `device_batt_volt_XXX`           |
| Current              | `current`        | `float`            | `device_batt_amp_XXX`            |
| Power                | `power`          | `float`            | `device_batt_power_XXX`          |
| Enabled              | `enabled`        | `bool`             | `device_batt_enabled_XXX`        |
| Percentage           | `percentage`     | `float`            | `device_batt_percentage_XXX`     |
| Capacity             | `capacity`       | `float`            | `device_batt_cap_XXX`            |
| Efficiency           | `efficiency`     | `float`            | `device_batt_efficiency_XXX`     |
| Time Remaining       | `time_remaining` | `float`            | `device_batt_time_remaining_XXX` |

### RadioTransceiver
The `RadioTransceiver` device corresponds to a radio transceiver. In the Artemis Cubesat, the [RFM98PW](https://www.hoperf.com/data/upload/portal/20190301/RFM98PW.pdf) is used.

| Supported Properties | Member Name         | Storage Type       | COSMOS Name               |
| -------------------- | ------------------- | ------------------ | ------------------------- |
| UTC Timestamp        | `utc`               | `double` or `Time` | `device_tcv_utc_XXX`      |
| Temperature          | `temperature`       | `float`            | `device_tcv_temp_XXX`     |
| Voltage              | `voltage`           | `float`            | `device_tcv_volt_XXX`     |
| Current              | `current`           | `float`            | `device_tcv_amp_XXX`      |
| Power                | `power`             | `float`            | `device_tcv_power_XXX`    |
| Enabled              | `enabled`           | `bool`             | `device_tcv_enabled_XXX`  |
| Frequency            | `frequency`         | `float`            | `device_tcv_freq_XXX`     |
| Maximum Frequency    | `max_frequency`     | `float`            | `device_tcv_maxfreq_XXX`  |
| Minimum Frequency    | `min_frequency`     | `float`            | `device_tcv_minfreq_XXX`  |
| Power In             | `power_in`          | `float`            | `device_tcv_powerin_XXX`  |
| Power Out            | `power_out`         | `float`            | `device_tcv_powerout_XXX` |
| Max Power            | `max_power`         | `float`            | `device_tcv_maxpower_XXX` |
| Good Packet Count    | `good_packet_count` | `int`              | `device_tcv_goodcnt_XXX`  |
| Bad Packet Count     | `bad_packet_count`  | `float`            | `device_tcv_badcnt_XXX`   |

### CPU
The `CPU` device corresponds to a CPU (central processing unit).

| Supported Properties | Member Name    | Storage Type       | COSMOS Name                 |
| -------------------- | -------------- | ------------------ | --------------------------- |
| UTC Timestamp        | `utc`          | `double` or `Time` | `device_cpu_utc_XXX`        |
| Temperature          | `temperature`  | `float`            | `device_cpu_temp_XXX`       |
| Voltage              | `voltage`      | `float`            | `device_cpu_volt_XXX`       |
| Current              | `current`      | `float`            | `device_cpu_amp_XXX`        |
| Power                | `power`        | `float`            | `device_cpu_power_XXX`      |
| Enabled              | `enabled`      | `bool`             | `device_cpu_enabled_XXX`    |
| Up Time              | `up_time`      | `int`              | `device_cpu_uptime_XXX`     |
| Boot Count           | `boot_count`   | `int`              | `device_cpu_boot_count_XXX` |
| Load                 | `load`         | `float`            | `device_cpu_load_XXX`       |
| Maximum Load         | `max_load`     | `float`            | `device_cpu_maxload_XXX`    |
| Memory Use           | `memory_usage` | `float`            | `device_cpu_gib_XXX`        |
| Maximum Memory Use   | `max_memory`   | `float`            | `device_cpu_maxgib_XXX`     |

### Camera
The `Camera` device corresponds to a camera. In the Artemis Cubesat, the [Raspberry Pi Camera Module V2](https://www.raspberrypi.org/documentation/hardware/camera/) is used.

| Supported Properties | Member Name    | Storage Type       | COSMOS Name              |
| -------------------- | -------------- | ------------------ | ------------------------ |
| UTC Timestamp        | `utc`          | `double` or `Time` | `device_cam_utc_XXX`     |
| Temperature          | `temperature`  | `float`            | `device_cam_temp_XXX`    |
| Voltage              | `voltage`      | `float`            | `device_cam_volt_XXX`    |
| Current              | `current`      | `float`            | `device_cam_amp_XXX`     |
| Power                | `power`        | `float`            | `device_cam_power_XXX`   |
| Enabled              | `enabled`      | `bool`             | `device_cam_enabled_XXX` |
| Pixel Width          | `pixel_width`  | `int`              | `device_cam_pwidth_XXX`  |
| Pixel Height         | `pixel_height` | `int`              | `device_cam_pheight_XXX` |
| Width                | `width`        | `float`            | `device_cam_width_XXX`   |
| Height               | `height`       | `float`            | `device_cam_height_XXX`  |
| Focal Length         | `focal_length` | `float`            | `device_cam_flength_XXX` |

### Switch
The `Switch` device corresponds to an electrical switch.

| Supported Properties | Member Name   | Storage Type       | COSMOS Name               |
| -------------------- | ------------- | ------------------ | ------------------------- |
| UTC Timestamp        | `utc`         | `double` or `Time` | `device_swch_utc_XXX`     |
| Temperature          | `temperature` | `float`            | `device_swch_temp_XXX`    |
| Voltage              | `voltage`     | `float`            | `device_swch_volt_XXX`    |
| Current              | `current`     | `float`            | `device_swch_amp_XXX`     |
| Power                | `power`       | `float`            | `device_swch_power_XXX`   |
| Enabled              | `enabled`     | `bool`             | `device_swch_enabled_XXX` |


### CustomDevice
The `CustomDevice` device can correspond to any device that does not fit into the COSMOS namespace.

| Supported Properties | Member Name   | Storage Type       | COSMOS Name                |
| -------------------- | ------------- | ------------------ | -------------------------- |
| UTC Timestamp        | `utc`         | `double` or `Time` | `device_pload_utc_XXX`     |
| Temperature          | `temperature` | `float`            | `device_pload_temp_XXX`    |
| Voltage              | `voltage`     | `float`            | `device_pload_volt_XXX`    |
| Current              | `current`     | `float`            | `device_pload_amp_XXX`     |
| Power                | `power`       | `float`            | `device_pload_power_XXX`   |
| Enabled              | `enabled`     | `bool`             | `device_pload_enabled_XXX` |

