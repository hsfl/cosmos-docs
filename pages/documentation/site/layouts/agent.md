---
title: Agent Layout
layout: page
permalink: /pages/documentation/site/layouts/agent.html

sidebar: dev_sidebar
search: exclude
---

## Brief

Pages documenting agents should use the `agent` layout. To do so, include the following in the page's frontmatter:

```yaml
layout: agent
```

The layout file is located under `_layouts/agent.html`.

## Page Format
The agent layout is structured as follows:

1. Quick Details Table
2. (page contents)
3. Request Table
4. COSMOS Device Table
5. Block Diagram

## Page Configuration
Every page using the `agent` layout should declare an agent name in their frontmatter. For example:

```yaml
agent_name: "agent_heater"
```

This will direct the layout to the corresponding YAML file (`_data/agents/agent_heater.yml` in the example above).


