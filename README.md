#Pulse Rate (BPM) Monitor using Arduino & Pulse Sensor#

In this project, we will interface a Pulse Sensor with an Arduino to measure heart rate (Beats Per Minute - BPM), with the results displayed on an OLED display instead of a traditional 16×2 LCD. The OLED display provides a sleek, modern look and is more compact, making it ideal for wearable or portable health monitoring devices.

Components Required:
Arduino Board: Any Arduino model, such as Arduino Uno or Nano, can be used for this project.
Pulse Sensor: A hardware device designed to detect heart rate in real-time.
OLED Display: We will use a small OLED display (e.g., 128x64) for visualizing the heart rate data.
Resistors and Jumper Wires: Basic electrical components for connecting the system.
Working Principle:
The pulse sensor operates by detecting the change in light absorption that occurs when blood is pumped through the fingertip. When you place your finger on the sensor, it shines a light through the skin, and as blood flows through the capillaries, the light reflected back to the sensor changes. These changes are converted into electrical signals, which the Arduino reads to calculate the BPM.

Project Setup:
Pulse Sensor Connection: The Pulse Sensor has three pins—VCC (power), GND (ground), and Signal. Connect the VCC to 5V on the Arduino, GND to ground, and the Signal pin to an analog input (e.g., A0).

OLED Display Setup: The OLED has four pins—VCC, GND, SCL, and SDA. Connect VCC to 5V, GND to ground, SCL to the Arduino’s SCL pin, and SDA to the SDA pin.

Code Overview:
Using an OLED display makes the project more visually appealing and informative. The code will continuously read data from the Pulse Sensor, calculate the BPM, and display it on the OLED. We will use libraries like Adafruit_GFX and Adafruit_SSD1306 to control the OLED display, and a simple algorithm to filter the pulse readings from the sensor.

This setup creates a compact, efficient, and portable heart rate monitoring system perfect for real-time health tracking.

