---

# Air Quality Monitor

## Overview
This project uses an Arduino to measure air quality levels using the MQ135 sensor. The air quality data is displayed on an LCD screen. This simple setup helps monitor the air quality in your environment to ensure a healthy living space.

## Components Needed
- **Arduino (e.g., Arduino Uno)**
- **MQ135 Air Quality Sensor**
- **16x2 LCD Display (with I2C interface)**
- **Wi-Fi Module (e.g., ESP8266)**
- **Breadboard and Jumper Wires**
- **Power Supply (e.g., 9V battery or USB power)**

## Wiring Diagram
1. **MQ135 Sensor:**
   - **VCC** to Arduino 5V
   - **GND** to Arduino GND
   - **AOUT** to Arduino Analog Pin A0

2. **LCD Display (I2C):**
   - **VCC** to Arduino 5V
   - **GND** to Arduino GND
   - **SDA** to Arduino A4
   - **SCL** to Arduino A5

3. **Wi-Fi Module (ESP8266):**
   - **VCC** to Arduino 3.3V
   - **GND** to Arduino GND
   - **TX** to Arduino RX
   - **RX** to Arduino TX

## Code
Here’s the Arduino sketch for reading the air quality sensor and displaying the data on the LCD:

```cpp
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
```

## Usage
1. **Assemble the Circuit:**
   - Connect the components as described in the wiring diagram.

2. **Upload the Code:**
   - Open the Arduino IDE, copy the provided code, and upload it to your Arduino board.

3. **View Results:**
   - The LCD will display the air quality sensor value. The Serial Monitor will show detailed readings for debugging.

## Calibration
The MQ135 sensor requires a warm-up period when first powered on. For accurate measurements, consider calibrating the sensor based on the specific environment and application.

## Troubleshooting
- **No Display on LCD:** Check the wiring connections and ensure the LCD address is correct.
- **Inaccurate Readings:** Ensure the sensor is properly warmed up and consider recalibrating if necessary.

## Future Enhancements
- Integrate the Wi-Fi module to send data to a cloud service or server for remote monitoring.
- Implement additional features such as air quality thresholds and alerts.


---
