#include <SPI.h>
#include <MFRC522.h>

#define duration_time   5000
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
MFRC522::MIFARE_Key key;

const byte UID[] = {0x43, 0x04, 0x50, 0x1B};

boolean led_state = false;
unsigned long led_time;

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
  pinMode(2, OUTPUT);
}

void loop() {
  if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    if(mfrc522.uid.uidByte[0] == UID[0] && 
        mfrc522.uid.uidByte[1] == UID[1] && 
        mfrc522.uid.uidByte[2] == UID[2] && 
        mfrc522.uid.uidByte[3] == UID[3]) {

        Serial.println("UID correct");
        led_state = true;
        led_time = millis() + duration_time;

    } else {

      Serial.println("UID incorrect");
        led_state = false;
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }

  if (led_state && led_time < millis()) {
    led_state = false;
  }

  digitalWrite(2, led_state);
}
