# Gate In Out

## Overview

Gate In Out is an Arduino-based people counting system developed as an embedded-systems exercise.

The system uses two ultrasonic sensors to detect people entering and leaving a room. The Arduino maintains the number of people inside and displays the count on an LCD.

## Circuit / Wokwi Simulation

![Gate In Out Wokwi Circuit](/Images/Embeded/gate%20in%20gate%20out%20circuit.png)

## Components

- Arduino Uno
- 2 × Ultrasonic sensors
- LCD display
- LED
- Breadboard
- Jumper wires

## Working

The system uses two separate gates:

- **Entry Gate:** Detects a person entering and increases the count by 1.
- **Exit Gate:** Detects a person leaving and decreases the count by 1.

The current number of people inside the room is displayed on the LCD.

The system also controls an LED based on the number of people inside. The LED remains ON while at least one person is inside and turns OFF when the count reaches zero.

## Assumption

The project is based on an ideal closed-room setup with only two gates:

- The entry gate is used only for entering.
- The exit gate is used only for leaving.
- There are no other entry or exit points.

## Simulation

The project was created and tested in **Wokwi**.

## Learning Outcomes

- Ultrasonic sensor interfacing
- LCD interfacing
- Counter logic
- Digital input handling
- Conditional programming
- Arduino programming
- Wokwi simulation

## Status

**Completed and tested.**