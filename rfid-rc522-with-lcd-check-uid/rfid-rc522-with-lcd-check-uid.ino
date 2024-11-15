#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define duration_time   5000
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
MFRC522::MIFARE_Key key;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const byte UID[] = {0x43, 0x04, 0x50, 0x1B};

boolean led_state = false;
unsigned long led_time;

String tagID = "";

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
  SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme

  lcd.begin(16, 2); // LCD screen

  lcd.clear();
  lcd.print(" Access Control ");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");

  pinMode(8, OUTPUT);
}

void loop() {
  if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {

    lcd.clear();
    lcd.setCursor(0, 0);

    if(mfrc522.uid.uidByte[0] == UID[0] && 
        mfrc522.uid.uidByte[1] == UID[1] && 
        mfrc522.uid.uidByte[2] == UID[2] && 
        mfrc522.uid.uidByte[3] == UID[3]) {

        tagID = "";
        for ( uint8_t i = 0; i < 4; i++) { // The MIFARE PICCs that we use have 4 byte UID
          //readCard[i] = mfrc522.uid.uidByte[i];
          tagID.concat(String(mfrc522.uid.uidByte[i], HEX)); // Adds the 4 bytes in a single String variable
        }
        tagID.toUpperCase();


        Serial.println("UID correct");
        Serial.println(tagID);

        lcd.print(" Access Granted!");
        led_state = true;
        led_time = millis() + duration_time;

    } else {

        Serial.println("UID incorrect");
        lcd.print(" Access Denied!");
        led_state = false;
    }

    lcd.setCursor(0, 1);
    lcd.print(" ID : ");
    lcd.print(tagID);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }

  if (led_state && led_time < millis()) {
    led_state = false;
    lcd.clear();
    lcd.print(" Access Control ");
    lcd.setCursor(0, 1);
    lcd.print("Scan Your Card>>");
  }

  digitalWrite(8, led_state);
}
