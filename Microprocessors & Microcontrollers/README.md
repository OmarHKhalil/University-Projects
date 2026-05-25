
# 🤖 Bluetooth-Controlled Dual LEDs with Dynamic GUI via RemoteXY

This project demonstrates wireless hardware control by interfacing an **Arduino Mega 2560** with an **HC-05 Bluetooth module**, allowing users to toggle two LEDs and stream physical sensor status to a customized smartphone Graphical User Interface (GUI) via the **RemoteXY** platform.

---

## 🎯 Main Features
* **📶 Wireless Dual LED Control:** Independent remote toggling of two physical LEDs (connected to Pins 12 & 13) using dynamic graphical switches on a mobile application.
* **🔘 Physical-to-Digital Status Streaming:** Monitors a hardware push button (Pin 9) using `digitalRead()`. Pressing the button streams and updates text fields on the smartphone screen dynamically (Toggling between `"Maha Qubais"` and the date `"2024/12/08"`).
* **🔌 Software Serial Architecture:** Employs virtual serial communication (`SoftwareSerial`) on Pins 10 (RX) and 11 (TX) to preserve the hardware Serial port for debugging.

---

## 🛠️ Components Used
* **Microcontroller:** Arduino Mega 2560 (or Compatible Board)
* **Wireless Module:** HC-05 Bluetooth Module
* **Actuators:** 2x LEDs (with appropriate current-limiting resistors)
* **Inputs:** 1x Tactile Push Button & 1x 10kΩ Pull-down Resistor
* **Prototyping:** Breadboard & Jumper Wires
* **Software:** Arduino IDE & RemoteXY Mobile App (Android/iOS)

---

## 🔌 Circuit Connections

### 💡 Actuators & Inputs
* **LED 1 (Red/Green):** Anode (+) ➡️ **Pin 13** (via resistor) | Cathode (-) ➡️ **GND**
* **LED 2 (Red/Green):** Anode (+) ➡️ **Pin 12** (via resistor) | Cathode (-) ➡️ **GND**
* **Push Button:** Connected to **Pin 9** with a 10kΩ pull-down resistor circuit configured between **+5V** and **GND**.

### 🔵 HC-05 Bluetooth Module
* **VCC** ➡️ **+5V** (Arduino)
* **GND** ➡️ **GND** (Arduino)
* **TXD** ➡️ **Pin 10** (Arduino RX)
* **RXD** ➡️ **Pin 11** (Arduino TX) *[Note: Voltage divider recommended for RXD lines]*

---

## 🚀 Setup & Deployment

1. **Install Library:** Download and add the `.zip` library for **RemoteXY** into your Arduino IDE (`Sketch` -> `Include Library` -> `Add .ZIP Library...`).
2. **Flash the Code:** Open the provided source sketch in the Arduino IDE, compile, and upload it to your board.
3. **App Configuration:** * Download the **RemoteXY** app from the Play Store or App Store.
   * Turn on Bluetooth on your mobile phone, open the application, select **Add New Device** ➡️ **Bluetooth**, and pair with the **HC-05** module.
4. **Operation:** Open the generated interface to start controlling the hardware instantly.

---

## 📁 Directory Structure
* `Code of Mpmc final project.txt` - The primary production Arduino sketch.
* `MPMC Project final.docx` - The official and comprehensive laboratory report.
* `README.md` - Technical specification and architecture summary.

---
*Disclaimer: This repository is maintained for educational and laboratory archival purposes under academic supervision.*