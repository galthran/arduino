#include <SoftwareSerial.h>

#define BT_RX 2  // Arduino receives from HC-05 TX
#define BT_TX 3  // Arduino sends to HC-05 RX (via voltage divider)
#define BT_KEY 4 // Controls AT mode

SoftwareSerial BTSerial(BT_RX, BT_TX);

bool atMode = true;

void setup() {
  pinMode(BT_KEY, OUTPUT);
  
  // Read AT mode flag from serial (or change here manually)
  // atMode = true; // Uncomment for AT mode by default
  
  if (atMode) {
    digitalWrite(BT_KEY, HIGH);   // Enter AT mode
    delay(100);
    Serial.begin(38400);          // AT mode baud
    BTSerial.begin(38400);
    Serial.println("AT mode ready");
  } else {
    digitalWrite(BT_KEY, LOW);    // Normal mode
    delay(100);
    Serial.begin(9600);
    BTSerial.begin(9600);
    Serial.println("Normal mode ready");
  }
}

void loop() {
  if (BTSerial.available()) Serial.write(BTSerial.read());
  if (Serial.available()) BTSerial.write(Serial.read());
}