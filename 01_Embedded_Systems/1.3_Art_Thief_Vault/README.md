# Art Thief Vault

## Overview

Art Thief Vault is an Arduino-based electronic vault project developed as a major embedded-systems exercise.

The project is based on a password-guessing concept where the user interacts with the vault through a keypad and receives feedback through an LCD, LEDs, and buzzer.

## Circuit / Wokwi Simulation

![Art Thief Vault Wokwi Circuit](/Images/Embeded/art%20thief%20vault%20circuit.png)


## Components

- Arduino Uno
- 4 × Servo motors
- Keypad
- LCD display
- Buzzer
- Red LED
- Green LED
- Supporting electronic components

## Working

The user enters a password using the keypad.

The entered value is checked and feedback is provided to help the user determine the correct password.

The system provides feedback such as:

- **Too High**
- **Too Low**
- **Correct**

When the correct password is achieved, the servo mechanisms are activated as part of the vault unlocking process.

Each servo represents a stage of the unlocking mechanism.

## System Flow

User Input → Keypad → Password Check → Feedback → Servo Activation → Vault Unlocking

## Simulation

The project was created and tested in **Wokwi**.

## Learning Outcomes

- Arduino programming
- Keypad interfacing
- LCD interfacing
- Servo motor control
- Password-based logic
- LED and buzzer control
- User feedback
- Wokwi simulation

## Project Development

This project helped develop the embedded-system concepts later used while working on the **Hackable Combination Vault** major project.

## Status

**Completed and tested.**