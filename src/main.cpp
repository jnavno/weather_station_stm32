#include <Arduino.h>

// Pin definitions
const int UVOUT = A0; // Sensor output connected to A0
const int EN = A1; // Enable pin connected to A1, which should be high

void setup() {
  Serial.begin(115200); // Initialize Serial communication
  pinMode(UVOUT, INPUT);
  pinMode(EN, OUTPUT);

  // Enable the sensor by setting EN to high
  digitalWrite(EN, HIGH);

  // Allow the sensor to warm up if necessary
  delay(2000);
}

int averageAnalogRead(int pinToRead) {
  const byte numberOfReadings = 16; // Number of readings for averaging
  unsigned int runningValue = 0;

  for(int x = 0; x < numberOfReadings; x++) {
    runningValue += analogRead(pinToRead);
    delay(10); // Delay to stabilize readings
  }
  runningValue /= numberOfReadings;

  return runningValue;
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
  int uvLevel = averageAnalogRead(UVOUT);

  // Use the 3.3V power pin as a reference to get a very accurate output value from the sensor
  float outputVoltage = 3.3 / 1023.0 * uvLevel; // 1023 is the maximum value from analogRead

  // Debugging output
  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);

  // Update mapping parameters based on sensor datasheet
  float uvIntensity = mapfloat(outputVoltage, 0.99, 2.8, 0.0, 15.0); // Adjust these values as needed

  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.println(uvIntensity);

  delay(500); // Delay before the next measurement
}
