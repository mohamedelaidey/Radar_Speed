# Arduino Speed Radar 🚗

This project is a simple **Speed Radar System** built using Arduino and two ultrasonic sensors.  
It measures the speed of an object moving between two sensors and displays the result on an LCD.

## Components Used
- Arduino Uno
- 2 × HC-SR04 Ultrasonic Sensors
- LCD 16x2 with I2C
- Buzzer
- Jumper wires
- Breadboard

## How It Works
1. The first ultrasonic sensor detects the object and records the start time.
2. The second sensor detects the object and records the end time.
3. The system calculates the time difference between the two sensors.
4. Speed is calculated and displayed on the LCD screen.
5. If the speed exceeds **50 km/h**, the buzzer activates and shows **Danger!**.

## Features
- Real-time speed calculation
- LCD display output
- Over-speed warning using buzzer
- Simple and low-cost radar simulation

## Programming Language
Arduino (C/C++)

## Author
Mohamed Elaidey
