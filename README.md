# AquaSense-

# SmartWaterMonitor 🚰

## 🌊 Water Level Monitoring System using NodeMCU & Blynk

This project is an **IoT-based water level monitoring system** that uses **NodeMCU ESP8266**, an **ultrasonic sensor**, and **Blynk** for real-time monitoring and motor control. It provides alerts and visual indicators using LEDs.

---

## 📌 Features

- ✅ **Real-time Water Level Monitoring** using an Ultrasonic Sensor (HC-SR04)
- ✅ **Blynk App Integration** to display water level data remotely
- ✅ **LED Indicators** for different water levels
- ✅ **Motor Control via Blynk** (Manually turn ON/OFF)
- ✅ **Wi-Fi-based Communication** using ESP8266
- ✅ **Automatic Pump Activation** based on water level thresholds *(Optional)*

---

## 🛠️ Components Used

- **NodeMCU ESP8266** (Wi-Fi Module)
- **HC-SR04 Ultrasonic Sensor** (For water level detection)
- **LEDs** (Water level indicators)
- **Relay Module** (For motor control)
- **Power Supply (5V/12V)**
- **Jumper Wires**
- **Water Tank (for testing)**

---


## 🔧 Setup & Installation

### 1️⃣ Install Required Libraries in Arduino IDE

- **ESP8266WiFi**
- **BlynkSimpleEsp8266**

### 2️⃣ Configure Blynk

1. Download the **Blynk App** (Android/iOS)
2. Create a new project and get the **Auth Token**
3. Set up **Virtual Pins (V0, V1, etc.)**

### 3️⃣ Upload Code to NodeMCU

- Open `SmartWaterMonitor.ino` in **Arduino IDE**
- Replace Wi-Fi & Blynk credentials:
  ```cpp
  char auth[] = "Your_Blynk_Auth_Token";
  char ssid[] = "Your_WiFi_Name";
  char pass[] = "Your_WiFi_Password";
  ```
- Select **Board: NodeMCU 1.0 (ESP-12E Module)**
- Upload the code

### 4️⃣ Connect Hardware & Test

- Power on the NodeMCU
- Open Blynk App & monitor water levels

---

## ⚡ How It Works

1. **Ultrasonic Sensor** measures water level distance
2. Data is sent to **NodeMCU**
3. NodeMCU updates **Blynk App** with water level
4. **LEDs turn ON/OFF** based on water level
5. **Relay activates the pump** when water is low *(if enabled)*

---

## 🛠️ Future Enhancements

- 🚀 Add **Automatic Pump Control** based on water level
- 📡 Integrate **LoRaWAN or MQTT** for remote access
- 📊 Display historical data using **Google Sheets or Firebase**

---

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
