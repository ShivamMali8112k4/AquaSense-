#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#include <BlynkSimpleEsp8266.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

BlynkTimer timer;

// Pin Definitions
#define trig D7
#define echo D8
#define LED1 D0
#define LED2 D3
#define LED3 D4
#define LED4 D5
#define LED5 D6
#define relay D1

// Water Level Thresholds
const int MaxLevel = 20;
const int Level1 = (MaxLevel * 75) / 100;
const int Level2 = (MaxLevel * 65) / 100;
const int Level3 = (MaxLevel * 55) / 100;
const int Level4 = (MaxLevel * 45) / 100;
const int Level5 = (MaxLevel * 35) / 100;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Configure Pin Modes
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(relay, OUTPUT);
  
  digitalWrite(relay, HIGH);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Display startup message
  lcd.setCursor(0, 0);
  lcd.print("Water level");
  lcd.setCursor(4, 1);
  lcd.print("Monitoring");
  delay(4000);
  lcd.clear();

  timer.setInterval(500L, ultrasonic); // Call ultrasonic function every 500ms
}

void ultrasonic() {
  // Measure distance using ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
  int distance = duration / 29 / 2;

  // Convert distance to water level percentage
  int blynkDistance = (distance > MaxLevel) ? 0 : (MaxLevel - distance);
  Blynk.virtualWrite(V0, blynkDistance);

  // Display water level on LCD and control LEDs accordingly
  lcd.setCursor(0, 0);
  lcd.print("WLevel: ");
  
  if (distance >= Level1) {
    lcd.setCursor(8, 0);
    lcd.print("Very Low ");
    controlLEDs(1, 0, 0, 0, 0);
  } 
  else if (distance >= Level2) {
    lcd.setCursor(8, 0);
    lcd.print("Low     ");
    controlLEDs(1, 1, 0, 0, 0);
  } 
  else if (distance >= Level3) {
    lcd.setCursor(8, 0);
    lcd.print("Medium  ");
    controlLEDs(1, 1, 1, 0, 0);
  } 
  else if (distance >= Level4) {
    lcd.setCursor(8, 0);
    lcd.print("High    ");
    controlLEDs(1, 1, 1, 1, 0);
  } 
  else {
    lcd.setCursor(8, 0);
    lcd.print("Full    ");
    controlLEDs(1, 1, 1, 1, 1);
  }
}

// Function to control LED indicators
void controlLEDs(int l1, int l2, int l3, int l4, int l5) {
  digitalWrite(LED1, l1);
  digitalWrite(LED2, l2);
  digitalWrite(LED3, l3);
  digitalWrite(LED4, l4);
  digitalWrite(LED5, l5);
}

// Blynk function to control relay (motor)
BLYNK_WRITE(V1) {
  bool Relay = param.asInt();
  digitalWrite(relay, Relay ? LOW : HIGH);
  
  lcd.setCursor(0, 1);
  lcd.print(Relay ? "Motor is ON " : "Motor is OFF");
}

void loop() {
  Blynk.run();
  timer.run(); // Execute timer events
}
