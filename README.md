# 🌊 Smart Water Monitoring System

## 📌 Project Overview
The **Smart Water Monitoring System** is an IoT-based project that utilizes a **NodeMCU ESP8266**, an **ultrasonic sensor**, and **Blynk Cloud** to measure and monitor water levels. The system provides real-time data, LED indicators for water levels, and remote control of a water pump.

## 🚀 Features
- **Real-time water level monitoring** using an **HC-SR04 ultrasonic sensor**.
- **LED indicators** to display different water level statuses.
- **Remote control of water pump** via the **Blynk app**.
- **LCD display (16x2)** for local water level status.
- **Wi-Fi connectivity** to send data to the Blynk cloud.

## 📡 Hardware Components
- **NodeMCU ESP8266** (Wi-Fi module & microcontroller)
- **HC-SR04 Ultrasonic Sensor** (for water level measurement)
- **16x2 LCD with I2C module** (for local display)
- **Relay Module** (to control the motor/pump)
- **5 LEDs** (to indicate different water levels)
- **Jumper Wires & Power Supply**

## 🖥️ Software & Libraries
- **Arduino IDE** (for coding & uploading firmware)
- **ESP8266WiFi** (for Wi-Fi connectivity)
- **BlynkSimpleEsp8266** (for cloud communication)
- **BlynkTimer** (for task scheduling)
- **ArduinoJson** (for data handling)
- **LiquidCrystal_I2C** (for LCD control)

## 🛠️ Setup & Installation
1. **Install Required Libraries:**
   - Open **Arduino IDE** and go to **Library Manager**.
   - Search and install the following libraries:
     - **BlynkSimpleEsp8266**
     - **ESP8266WiFi**
     - **LiquidCrystal_I2C**
     - **ArduinoJson**
2. **Setup Blynk App:**
   - Create a new project in **Blynk**.
   - Add **Virtual Pins** for water level monitoring and motor control.
   - Get the **Blynk Auth Token** and update it in the code.
3. **Configure Wi-Fi:**
   - Update the **SSID** and **password** in the code.
4. **Upload the Code:**
   - Connect **NodeMCU** to your PC and upload the **Code.ino** file using Arduino IDE.
5. **Connect the Hardware:**
   - Follow the circuit diagram and connect components accordingly.
6. **Run & Monitor:**
   - Open **Blynk app** and monitor real-time water levels.
   - Use the app to turn the water pump ON/OFF.

## ⚙️ How It Works
1. **Water level measurement:**
   - The **HC-SR04 sensor** measures the distance of water from the sensor.
   - The data is processed and mapped to predefined levels.
2. **LED indicators:**
   - LEDs light up based on the water level.
3. **LCD Display:**
   - Shows real-time water level status.
4. **Blynk App & Cloud:**
   - Sends water level data to **Blynk**.
   - Allows remote control of the water pump.

## 🔄 Future Enhancements
- Add **LoRaWAN/MQTT** support for remote monitoring.
- Integrate **Google Sheets/Firebase** for data logging.
- Implement **automatic motor activation** based on water level.

## 📜 License

This project is open-source under the **MIT License**.

---

## 🤝 Contributing

Pull requests are welcome! Feel free to improve or add new features.

---

## 📩 Contact

For queries, reach out via **GitHub Issues** or email me at **[shivammali8112k4@gmail.com](mailto\:shivammali4248@gmail.com)**.

###



---

### ⭐ If you found this useful, please give it a star! ⭐


📌 *This project ensures efficient water usage and prevents overflow!* 🚀
