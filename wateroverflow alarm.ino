const int waterSensorPin = 2; // Connect sensor/wire pin here
const int buzzerPin = 8;     // Connect buzzer or relay pin here

void setup() {
  pinMode(waterSensorPin, INPUT_PULLUP); // Set sensor pin as input with pull-up
  pinMode(buzzerPin, OUTPUT);          // Set buzzer pin as output
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(waterSensorPin);

  // Assuming LOW means water touches the sensor (grounded through water)
  if (sensorState == LOW) {
    digitalWrite(buzzerPin, HIGH); // Turn on alarm
    Serial.println("Water Tank Full! Overflow Alert!");
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off alarm
    Serial.println("Water level normal.");
  }
  
  delay(500); // Wait half a second before next check
}
