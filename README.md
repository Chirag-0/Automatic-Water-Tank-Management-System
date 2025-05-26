# Automatic Water Tank Level Management System

This project is a smart **IoT-based solution** to automate water tank monitoring and control. It eliminates the need to manually check and fill water tanks — helping you **save water, energy, and time**.

---

## What It Does

- Measures water level in a tank using an **ultrasonic sensor**
- Automatically **turns ON** a pump when water is low
- Automatically **turns OFF** the pump to prevent overflow
- **Remotely monitors** tank level on your phone via the **Blynk app**
- Prevents **pump dry-run** using a water presence sensor
- Supports **manual control** using smartphone if needed

---

## How It Works

- The **ESP32 microcontroller** reads data from the **ultrasonic sensor**
- Based on water level, it controls the **relay module**, which switches the **water pump** and **solenoid valve**
- Data is pushed to the **Blynk IoT platform**, so you can see live tank levels on your phone
- The system can also send you alerts when water is too low or too high

---

## Hardware Used

- ESP32 development board  
- Ultrasonic Sensor (HC-SR04)  
- 2-Channel Relay Module  
- Water Pump (12V DC)  
- Solenoid Valve (12V DC)  
- Water Level Sensor (for source detection)  
- Power Supply (5V for ESP32, 12V for pump/valve)  
- Connecting wires and breadboard

---

## Software Used

- Arduino IDE (to write and upload code)  
- Blynk IoT Platform (mobile app for monitoring/control)  
- Libraries:  
  - `WiFi.h`  
  - `BlynkSimpleEsp32.h`

---

## Wiring Overview

- Trig and Echo pins of Ultrasonic → ESP32 GPIOs  
- Relay IN1 → Controls Pump (GPIO 15)  
- Relay IN2 → Controls Solenoid Valve (GPIO 16)  
- Water Sensor → Analog Pin (e.g. GPIO 34)  
- Blynk → Displays water level and provides control buttons


---
---

## Getting Started

1. Clone or download this repo
2. Open `autotank.ino` in Arduino IDE
3. Enter your:
   - Wi-Fi SSID and password
   - Blynk Auth Token
4. Upload to your ESP32 board
5. Connect hardware as per wiring
6. Monitor tank levels from your Blynk app!

---

## Credits

Developed by:
- Chirag Chouhan  
- Ankit Singh Tomar  
- Arbaz Khan  
- Monika Pardhi  

Under the guidance of **Prof. Ram Ratan Ahirwal**,  
Samrat Ashok Technological Institute, Vidisha (M.P.)

---

## Why This Matters

Water is a limited resource — and millions of liters are wasted every year due to overflows, leaks, and manual errors.  
This project helps move toward **smarter, sustainable, and more responsible water management** using accessible technology.

---

