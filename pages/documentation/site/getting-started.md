---
title: Getting Started
layout: page
permalink: /pages/documentation/site/getting-started.html

sidebar: dev_sidebar
search: exclude
---

## Set Up for Local Testing

Modifying the website, committing changes, and waiting for GitHub pages to regenerate the site is _painfully_ slow.
You should definitely set up Jekyll for local testing. As of now, Jekyll doesn't seem to support local testing
on Windows machines.

{% include important.html content="It has been noted that local builds may not match up completely
with GitHub Pages builds. Be cautious when writing pages!" %}

### 1. Install Ruby

Visit the [Jekyll installation page](https://jekyllrb.com/docs/installation/) and follow the steps to install Ruby and
Ruby Gems.

### 2. Install the Jekyll and Bundler Gems
Run the command:

```bash
$ gem install jekyll bundler
```

### 3. Clone the Site Repo
In a terminal change directory to a folder you feel comfortable working from, and run the following command:

```bash
$ git clone https://github.com/mtmk-ee/artemis-docs.git
```

### 4. Install the Site Dependencies
Next, run the following commands:

```bash
$ cd artemis-docs
$ bundle install
```

### 5. View the Site

To start up the site, run the following command:

```bash
$ bundle exec jekyll serve --trace
```

Since this is a bit long to type in each time, there is a `serve.sh` shell script in the root of the repository.

## Read the Docs
To find out more about how Jekyll works, visit their [documentation](https://jekyllrb.com/docs/). You don't need to
follow their steps for creating a new site, since you're already using this one.

You should also check out [how Liquid is used](https://jekyllrb.com/docs/liquid/), since this site uses a _ton_ of it.
Documentation on the language itself is located [here](https://shopify.github.io/liquid/).

## Pushing Your Changes

To get your changes published, run the following commands from your cloned repo:

```bash
$ git add .
$ git commit -m "YOUR MESSAGE HERE"
$ git push origin
```

GitHub Pages will take a minute or two to regenerate your site, but then you should be able to see your changes.