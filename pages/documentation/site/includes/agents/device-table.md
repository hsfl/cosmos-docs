---
title: COSMOS Device Table
layout: page
permalink: /pages/documentation/site/includes/agents/device-table.html

sidebar: dev_sidebar
search: exclude
---

## Brief
The "Device Table" include generates a table of COSMOS properties for a page using the `agent` layout.

This can be included in a page by using the following code:

{% raw %}
`{% include agents/device_table.html %}`
{% endraw %}


## The YAML File

This requires that a YAML file be placed in the `_data/agents` folder named according to the agent page's `agent_name` frontmatter field.

Here is an example taken from the `_data/agents/agent_heater.yml` YAML file:

```yaml
cosmos_devices:

  - name: "Heater"
    cosmos_device_name: "htr"
    cosmos_device_number: "000"
    properties:
      - name: "UTC"
        cosmos_name: "utc"
        storage_type: ["double", "Time"]
        description: "The UTC timestamp as a Modified Julian Day"
        
      - name: "Enabled"
        cosmos_name: "enabled"
        storage_type: "bool"
        description: "`true` if the device is enabled"
        
      - name: "Voltage (V)"
        cosmos_name: "volt"
        storage_type: "float"
        description: "The voltage supplied"

# Node Property table (commented since agent_heater doesn't use node properties)
# cosmos_node:
#   - name: "Enabled"
#     cosmos_name: "enabled"
#     storage_type: "bool"
#     description: "`true` if the device is enabled"
```
