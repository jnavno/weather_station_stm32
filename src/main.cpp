#include <Arduino.h>

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    Serial.println("Hello PlatformIO!");
}

void loop() {
    // Print a message every second
    Serial.println("Running...");
    delay(1000);
}