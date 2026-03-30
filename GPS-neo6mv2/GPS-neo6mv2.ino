#include "Arduino.h"
#include "uRTCLib.h"
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

uRTCLib rtc(0x68);

const int chipSelect = 10;
File myFile;

int RXPin = 3;
int TXPin = 2;

SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSPlus gps;

void setup() {
  delay (2000);
	Serial.begin(115200);
	Serial.println("Serial OK");

  #ifdef ARDUINO_ARCH_ESP8266
		URTCLIB_WIRE.begin(0, 2); // D3 and D4 on ESP8266
	#else
		URTCLIB_WIRE.begin();
	#endif

  //  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
	rtc.set(0, 7, 20, 1, 11, 8, 25);

	Serial.println("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed!");
    //return;
  }
  Serial.println("initialization done.");

	gpsSerial.begin(9600);

	Serial.println("GPS test...");

  delay(3000); // czas na uruchomienie modułu

  unsigned long start = millis();
  while (millis() - start < 5000) {
    if (gpsSerial.available()) {
      char c = gpsSerial.read();
      Serial.write(c); // Powinny się pojawić linie zaczynające się od $GP
    }
  }

  Serial.println("Koniec testu GPS");
}

void loop() {
  rtc.refresh();

	Serial.print("RTC DateTime: ");
	Serial.print(rtc.year());
	Serial.print('/');
	Serial.print(rtc.month());
	Serial.print('/');
	Serial.print(rtc.day());

	Serial.print(' ');

	Serial.print(rtc.hour());
	Serial.print(':');
	Serial.print(rtc.minute());
	Serial.print(':');
	Serial.print(rtc.second());

	Serial.println();

	/*Serial.print("gpsSerial: ");
	Serial.print(gpsSerial.available());
	Serial.println();*/

	if(gpsSerial.available() > 0) {
		gps.encode(gpsSerial.read());
		Serial.println(gps.date.value());
		Serial.print("GPS Date: ");
		if (gps.date.isValid()) {
			Serial.print(gps.date.month());
			Serial.print("/");
			Serial.print(gps.date.day());
			Serial.print("/");
			Serial.println(gps.date.year());
		}
		if (gps.time.isValid()) {
			if (gps.time.hour() < 10) myFile.print(F("0"));
			Serial.print(gps.time.hour());
			Serial.print(":");
			if (gps.time.minute() < 10) myFile.print(F("0"));
			Serial.print(gps.time.minute());
			Serial.print(":");
			if (gps.time.second() < 10) myFile.print(F("0"));
			Serial.print(gps.time.second());
			Serial.print(".");
			if (gps.time.centisecond() < 10) myFile.print(F("0"));
			Serial.println(gps.time.centisecond());
		}
		if (gps.location.isValid()) {
			Serial.print("Latitude: ");
			Serial.println(gps.location.lat(), 6);
			Serial.print("Longitude: ");
			Serial.println(gps.location.lng(), 6);
			Serial.print("Altitude: ");
			Serial.println(gps.altitude.meters());
		}
		if(gps.satellites.isValid()) {
			Serial.print("satellites: ");
			Serial.println(gps.satellites.value());
		}
	}

	//writeToFile(rtc.year(), rtc.month(), rtc.day(), rtc.hour(), rtc.minute(), rtc.second(), gps);
	delay(5000);
}

/*void writeToFile(int year, int month, int day, int hour, int minute, int sec, TinyGPSPlus &gpsObj) {
  myFile = SD.open("gps-data2.txt", FILE_WRITE);

  if (myFile) {
		myFile.println("====================");
		myFile.print("RTC DateTime: ");
    String datetime = String(day) + "." + month + "." + year + " " + hour + ":" + minute + ":" + sec;
    myFile.println(datetime);

		if(gpsSerial.available() > 0) {
			myFile.print("GpsSerial.available: ");
			myFile.println(gpsSerial.available());
			gps.encode(gpsSerial.read());
		} else {
			myFile.println("GpsSerial.available: 0");
		}

		myFile.print("GPS Date: ");
		if (gpsObj.date.isValid()) {
			myFile.print(gpsObj.date.month());
			myFile.print("/");
			myFile.print(gpsObj.date.day());
			myFile.print("/");
			myFile.println(gpsObj.date.year());
		} else {
			myFile.println("Not Available");
		}

		myFile.print("GPS Time: ");
		if (gpsObj.time.isValid()) {
			if (gpsObj.time.hour() < 10) myFile.print(F("0"));
			myFile.print(gpsObj.time.hour());
			myFile.print(":");
			if (gpsObj.time.minute() < 10) myFile.print(F("0"));
			myFile.print(gpsObj.time.minute());
			myFile.print(":");
			if (gpsObj.time.second() < 10) myFile.print(F("0"));
			myFile.print(gpsObj.time.second());
			myFile.print(".");
			if (gpsObj.time.centisecond() < 10) myFile.print(F("0"));
			myFile.println(gpsObj.time.centisecond());
		} else {
			myFile.println("Not Available");
		}

		myFile.print("GPS Location: ");
		if (gpsObj.location.isValid()) {
			myFile.print("Latitude: ");
			myFile.println(gpsObj.location.lat(), 6);
			myFile.print("Longitude: ");
			myFile.println(gpsObj.location.lng(), 6);
			myFile.print("Altitude: ");
			myFile.println(gpsObj.altitude.meters());
		} else {
			myFile.println("Location: Not Available");
		}

		if(gps.satellites.isValid()) {
			myFile.print("satellites: ");
			myFile.println(gps.satellites.value());
		}

		myFile.println("====================");
    myFile.close();
  }
}*/

