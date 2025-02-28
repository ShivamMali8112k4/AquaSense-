#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "xyz"
#define BLYNK_TEMPLATE_NAME "xyz"

char auth[] = "xyz";
char ssid[] = "xyz";
char pass[] = "xyz";

BlynkTimer timer;

#define trig D7
#define echo D8
#define LED1 D0
#define LED2 D3
#define LED3 D4
#define LED4 D5
#define LED5 D6
#define relay D1

const int MaxLevel = 20;
const int Level1 = (MaxLevel * 75) / 100;
const int Level2 = (MaxLevel * 65) / 100;
const int Level3 = (MaxLevel * 55) / 100;
const int Level4 = (MaxLevel * 45) / 100;
const int Level5 = (MaxLevel * 35) / 100;

void setup() {
  Serial.begin(9600);
  
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

  timer.setInterval(500L, ultrasonic);
}

void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
  int distance = duration / 29 / 2;

  int blynkDistance = (distance > MaxLevel) ? 0 : (MaxLevel - distance);
  Blynk.virtualWrite(V0, blynkDistance);

  if (distance >= Level1) {
    controlLEDs(1, 0, 0, 0, 0);
  } 
  else if (distance >= Level2) {
    controlLEDs(1, 1, 0, 0, 0);
  } 
  else if (distance >= Level3) {
    controlLEDs(1, 1, 1, 0, 0);
  } 
  else if (distance >= Level4) {
    controlLEDs(1, 1, 1, 1, 0);
  } 
  else {
    controlLEDs(1, 1, 1, 1, 1);
  }
}

void controlLEDs(int l1, int l2, int l3, int l4, int l5) {
  digitalWrite(LED1, l1);
  digitalWrite(LED2, l2);
  digitalWrite(LED3, l3);
  digitalWrite(LED4, l4);
  digitalWrite(LED5, l5);
}

BLYNK_WRITE(V1) {
  bool Relay = param.asInt();
  digitalWrite(relay, Relay ? LOW : HIGH);
}

void loop() {
  Blynk.run();
  timer.run();
}
