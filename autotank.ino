#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk Auth & Wi-Fi Credentials
char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

// Ultrasonic Sensor Pins
#define trigPin 4
#define echoPin 5

// Pump and Valve Pins
#define pumpPin 15
#define valvePin 16

// Water Level Thresholds (in cm)
int minLevel = 10; // When to start pump
int maxLevel = 2;  // When to stop pump

long duration;
int distance;

// Setup function
void setup() {
  // Start Serial Monitor
  Serial.begin(115200);

  // Setup pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(valvePin, OUTPUT);

  // Initialize components OFF
  digitalWrite(pumpPin, LOW);
  digitalWrite(valvePin, LOW);

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);
}

// Function to measure distance from ultrasonic sensor
void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance (Water Level): ");
  Serial.print(distance);
  Serial.println(" cm");
}

void loop() {
  Blynk.run();
  measureDistance();

  // Send water level to Blynk gauge widget (V0)
  Blynk.virtualWrite(V0, distance);

  // Control logic for pump and valve
  if (distance > minLevel) {
    digitalWrite(pumpPin, HIGH);
    digitalWrite(valvePin, HIGH);
  } else if (distance < maxLevel) {
    digitalWrite(pumpPin, LOW);
    digitalWrite(valvePin, LOW);
  }

  delay(1000); // Delay between readings
}
