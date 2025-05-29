# Temperature-adapted-fan - Simple-project-using-Arduino

# 🌡️ Temperature-Controlled Fan System Using Arduino

A low-cost, smart, temperature-responsive AC fan system designed for comfort, energy efficiency, and usability—especially for the elderly and teenagers. This project dynamically adjusts fan speed based on ambient room temperature using an Arduino microcontroller and a set of reliable electronic components.

---

## 📌 Problem Statement

In Sri Lanka's tropical climate, fans are heavily relied upon. However, misuse such as always running fans at full speed leads to excessive power consumption. Elderly individuals struggle to adjust fan settings, and teenagers often ignore power-saving habits. This project proposes a smart system that automates fan control based on room temperature, helping reduce energy waste and improving convenience.

---

## 🎯 Project Goals

### Aims:
- Create a comfortable living environment for elderly users by automating fan control.
- Improve energy efficiency through dynamic fan speed adjustment.

### Objectives:
- Reduce electricity consumption by avoiding unnecessary high-speed fan operation.
- Offer a cost-effective alternative to air conditioning.
- Enhance comfort without requiring user intervention or reliance on remotes.

---

## 🧠 Features

- Automatically adjusts fan speed based on room temperature.
- Fully turns off the fan when the temperature is below comfort threshold.
- Simple LED indicators reflect the fan's current operational state.
- Easy to install, inexpensive, and ideal for home or small office use.

---

## 🛠️ Technologies Used

| Component       | Purpose                                                |
|----------------|--------------------------------------------------------|
| **Arduino**     | Microcontroller for logic and control signals         |
| **DHT11**       | Temperature and humidity sensor                        |
| **PC817**       | Optocoupler to isolate microcontroller from AC        |
| **MOC3021**     | TRIAC driver to trigger AC fan                         |
| **BTA16**       | TRIAC for controlling 220V fan load                    |
| **C++ (Arduino)**| Program to process sensor data and control speed     |

---

## 🔧 Methodology

The system uses an Arduino to read room temperature from a **DHT11** sensor. Based on this reading, it controls an AC fan’s speed using a **TRIAC** and **MOC3021 opto-isolator**. A **PC817 optocoupler** safely detects zero crossings of the AC waveform, allowing for timed pulses that determine how much power is sent to the fan.

Fan speed logic:

| Temperature Range | Fan Status | Speed Level |
|-------------------|------------|-------------|
| < 28°C            | OFF        | 0%          |
| 28–30°C           | ON         | 50%         |
| 30–32°C           | ON         | 75%         |
| > 32°C            | ON         | 100%        |

---

## 💻 Code Sample (Excerpt)

Code is mentioned in the file `code_of__the_project.INO` file 


## ⚙️ Setup Diagram

![image](https://github.com/user-attachments/assets/4fe904bb-2f8e-4797-8f1d-7ba3daf8dfb7)


 Test results are shown in the `Arduino Temperature Controlled Fan Speed.mp4`

