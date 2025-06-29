#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ZMPT101B.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SENSITIVITY 500.0f

// ZMPT101B sensor output connected to analog pin A0
// and the voltage source frequency is 50 Hz.
ZMPT101B voltageSensor(A0, 50.0);

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float zmpt101b1_value = 0;
float zmpt101b2_value = 0;
float zmpt101b3_value = 0;

float l1_voltage = 0;
float l2_voltage = 0;
float l3_voltage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  voltageSensor.setSensitivity(SENSITIVITY);

  // initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

}

void loop() {

  l1_voltage = voltageSensor.getRmsVoltage();

  // zmpt101b1_value = analogRead(A0);
  // l1_voltage = zmpt101b1_value * (5.0/1024.0);
  // Serial.println(l1_voltage);

  // zmpt101b2_value = analogRead(A1);
  // l2_voltage = zmpt101b2_value * (5.0/1024.0);
  // Serial.println(l2_voltage);

  // zmpt101b3_value = analogRead(A2);
  // l3_voltage = zmpt101b3_value * (5.0/1024.0);
  // Serial.println(l3_voltage);

  // if (l1_voltage > 2.50) {
  //   digitalWrite(2, HIGH);
  // } else {
  //   digitalWrite(2, LOW);
  // }

  String line1 = "L1:" + String(l1_voltage) + "V";
  String line2 = "L2:" + String(l2_voltage) + "V";
  String line3 = "L3:" + String(l3_voltage) + "V";

  // Display Text
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(line1);
  // display.println(line2);
  // display.println(line3);
  
  display.display();

  delay(1000);
}
