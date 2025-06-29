#include "Arduino.h"
#include "uRTCLib.h"

// uRTCLib rtc;
uRTCLib rtc(0x68);

void setup() {
  delay (2000);
	Serial.begin(9600);
	Serial.println("Serial OK");

  #ifdef ARDUINO_ARCH_ESP8266
		URTCLIB_WIRE.begin(0, 2); // D3 and D4 on ESP8266
	#else
		URTCLIB_WIRE.begin();
	#endif

  //  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
	rtc.set(0, 35, 14, 1, 29, 6, 25);

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

	Serial.print(" DOW: ");
	Serial.print(rtc.dayOfWeek());

	Serial.print(" - Temp: ");
	Serial.print(rtc.temp()  / 100);

	Serial.println();

	delay(1000);

}
