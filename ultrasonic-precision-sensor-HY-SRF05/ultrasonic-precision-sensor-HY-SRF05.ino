#include "NewPing.h"

#define FRONT_TRIGGER_PIN 10
#define FRONT_ECHO_PIN 11

#define BACK_TRIGGER_PIN 12
#define BACK_ECHO_PIN 13

#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing frontSonar(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, MAX_DISTANCE);
NewPing backSonar(BACK_TRIGGER_PIN, BACK_ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance = ");
	Serial.print(frontSonar.ping_cm());
	Serial.println(" cm");

  if(frontSonar.ping_cm() < 10) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if(backSonar.ping_cm() < 10) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

	delay(500);
}
