# Debouncer

## Overview

Debouncer is a basic Arduino project developed to understand **button debouncing**.

A push button can produce multiple unwanted signals when pressed or released. This project uses a simple software-based approach to handle this issue.

## Circuit / Wokwi Simulation

![Debouncer Wokwi Circuit](/Images/Embeded/debouncer%20circuit.png)

## Components

- Arduino Uno
- Push button
- LED
- Resistor
- Breadboard
- Jumper wires

## Working

The push button is connected to the Arduino as a digital input. When the button is pressed, the Arduino detects the input and controls the LED.

A debounce technique is used to prevent unwanted multiple detections caused by the mechanical movement of the button.

## Simulation

The project was created and tested in **Wokwi**.

## Learning Outcomes

- Digital input handling
- Push-button interfacing
- LED control
- Button debouncing
- Basic Arduino programming
- Wokwi simulation

## Status

**Completed and tested.**