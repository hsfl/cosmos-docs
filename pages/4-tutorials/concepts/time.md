---
title: COSMOS Time System
permalink: /pages/4-tutorials/concepts/time.html
layout: series
index: 4.1.1
tags: [software]
keywords: software
series:
    language: "C++"
    next: /pages/4-tutorials/concepts/libraries.html
---

# Coordinated Universal Time and Modified Julian Date

COSMOS keeps track of time based on two concepts, **Coordinated Universal Time(UTC)** and **Modified Julian Date(MJD)**.

**Coordinated Universal Time (UTC)** is a successor to Greenwich Mean Time (GMT). It is based on the solar time at 0 degrees longitude. In order to maintain its accuracy to Universal Time (UT), UTC adds in "leap seconds" (an extra second in a day) to adjust as needed.

**Modified Julian Date (MJD)** is a modified version of the Julian Date (JD) system. The JD system is a base 10 (decimal) measure of time where days are measured as whole numbers. While the JD system's time 0 is noon on January 1, 4713 BC, proleptic Julian calendar (November 24, 4714 BC, in the proleptic Gregorian calendar), the MJD was given the starting point of midnight on Nov 17, 1858, reducing the date by 2400000.5 (midnight of June 25, 2017: 2457929.5(JD) to 57929.0(MJD)).
