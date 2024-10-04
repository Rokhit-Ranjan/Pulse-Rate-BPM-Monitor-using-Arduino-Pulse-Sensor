
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 

// Create an OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Constants
const int PULSE_SENSOR_PIN = 0;  // Analog PIN where the PulseSensor is connected
const int LED_PIN = 13;          // On-board LED PIN
const int THRESHOLD = 550;       // Threshold for detecting a heartbeat

// Create PulseSensorPlayground object
PulseSensorPlayground pulseSensor;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C is the I2C address for the OLED
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.display();

  // Configure PulseSensor
  pulseSensor.analogInput(PULSE_SENSOR_PIN);
  pulseSensor.blinkOnPulse(LED_PIN);
  pulseSensor.setThreshold(THRESHOLD);

  // Check if PulseSensor is initialized
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor object created successfully!");
  }
}

void loop() {
  // Get the current Beats Per Minute (BPM)
  int currentBPM = pulseSensor.getBeatsPerMinute();

  // Clear previous display content
  display.clearDisplay();

  // Display static text "Heart Rate"
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Heart Rate");

  // Check if a heartbeat is detected
  if (pulseSensor.sawStartOfBeat()) {
    Serial.println("♥ A HeartBeat Happened!");
    Serial.print("BPM: ");
    Serial.println(currentBPM);

    // Display current BPM
    display.setTextSize(2);  // Larger font for BPM
    display.setCursor(0, 20);
    display.print("BPM: ");
    display.print(currentBPM);
  }

  // Display the updated content on the OLED
  display.display();

  // Add a small delay to reduce CPU usage
  delay(20);
}
