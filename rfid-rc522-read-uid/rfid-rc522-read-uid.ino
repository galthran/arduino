#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
}

void loop() {
  if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("UID: {");
    Serial.print(mfrc522.uid.uidByte[0] < 0x10 ? "0x0" : "0x");
    Serial.print(mfrc522.uid.uidByte[0], HEX);
    Serial.print(mfrc522.uid.uidByte[1] < 0x10 ? "0x0" : "0x");
    Serial.print(mfrc522.uid.uidByte[1], HEX);
    Serial.print(mfrc522.uid.uidByte[2] < 0x10 ? "0x0" : "0x");
    Serial.print(mfrc522.uid.uidByte[2], HEX);
    Serial.print(mfrc522.uid.uidByte[3] < 0x10 ? "0x0" : "0x");
    Serial.print(mfrc522.uid.uidByte[3], HEX);
    Serial.println("}");
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}
