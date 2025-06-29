#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ZMPT101B.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define SENSITIVITY 500.0f

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//ZMPT101B voltageSensor(A0, 50.0);




void setup() {
  Serial.begin(9600);

   //voltageSensor.setSensitivity(SENSITIVITY);

  // initialize the OLED object
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);

}

void loop() {

  Serial.println("test");
  int rowValue = analogRead(A0);
  Serial.println(rowValue);

  float voltage = (rowValue / 1023.0) * 5.0 * 0.56;
  Serial.print("voltage: ");
  Serial.println(voltage);


  //  float voltage = voltageSensor.getRmsVoltage();
  //  Serial.println(voltage);

  // Display Text
  // display.clearDisplay();
  // display.setTextSize(2);
  // display.setTextColor(WHITE);
  // display.setCursor(0, 0);
  // display.println("aaaa");

  // display.display();

  delay(1000);
}
