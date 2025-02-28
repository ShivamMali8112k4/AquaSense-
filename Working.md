# 🛠️ Working of Smart Water Monitoring System

## 📌 Overview
This system monitors water levels in a tank using an **ultrasonic sensor** and displays the status on an **LCD screen** while also sending data to the **Blynk cloud**. The system allows remote monitoring and **manual control of the water pump** via the Blynk app.

## ⚙️ Working Principle
1. **Water Level Measurement:**
   - The **HC-SR04 Ultrasonic Sensor** emits a signal and measures the time taken for the echo to return.
   - The calculated distance is compared with predefined levels to determine the water level.
   
2. **Real-time Display:**
   - The water level is displayed on a **16x2 LCD** using the **LiquidCrystal_I2C** library.
   - **LED indicators** light up according to the water level.
   
3. **Blynk Cloud Integration:**
   - The **ESP8266** sends real-time water level data to the **Blynk cloud**.
   - Users can monitor water levels remotely via the **Blynk app**.
   
4. **Motor Control:**
   - The water pump can be turned **ON/OFF manually** using a button in the **Blynk app**.
   - The **relay module** controls the pump operation based on user input.
   
## 🔄 Workflow
1. **System Startup:**
   - The NodeMCU initializes and connects to the **Wi-Fi network**.
   - The LCD displays a startup message.
   
2. **Sensor Data Processing:**
   - The ultrasonic sensor measures the water level.
   - Data is processed and sent to the LCD and **Blynk cloud**.
   
3. **LED & LCD Indication:**
   - Different **LEDs** indicate various water levels.
   - The LCD provides real-time status.
   
4. **User Control via Blynk App:**
   - Users monitor water levels remotely.
   - Users can manually control the pump from the app.
   
## 📊 Data Flow
- **Sensor ➝ NodeMCU ➝ LCD & LEDs** (Local Display)
- **NodeMCU ➝ Blynk Cloud ➝ Mobile App** (Remote Monitoring)
- **Mobile App ➝ Blynk Cloud ➝ NodeMCU ➝ Relay** (Pump Control)

## ✅ Advantages
- **Prevents Water Wastage** by monitoring levels accurately.
- **Remote Access** via smartphone.
- **User-friendly Interface** with LED and LCD indications.
- **Energy Efficient** as the pump runs only when required.

📌 *This system ensures efficient water management and automation!* 🚀

