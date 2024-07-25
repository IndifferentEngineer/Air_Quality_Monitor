#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address and size
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27 for a 16 chars and 2-line display

// Pin definitions
const int mq135Pin = A0;

void setup() {
  // Initialize the LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality:");

  // Set up the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(mq135Pin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float airQuality = voltage; // For simplicity, we're just showing voltage

  // Display on LCD
  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(sensorValue);
  lcd.print("    "); // Clear extra characters

  // Print to Serial Monitor (for debugging purposes)
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" - Voltage: ");
  Serial.print(voltage);
  Serial.print("V - Air Quality: ");
  Serial.println(airQuality);

  delay(2000); // Update every 2 seconds
}
