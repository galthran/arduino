#include "NewPing.h"

#define FRONT_TRIGGER_PIN 10
#define FRONT_ECHO_PIN 11

#define BACK_TRIGGER_PIN 12
#define BACK_ECHO_PIN 13

#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing frontSonar(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, MAX_DISTANCE);
NewPing backSonar(BACK_TRIGGER_PIN, BACK_ECHO_PIN, MAX_DISTANCE);

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

boolean frontDir;
boolean backDir;

void setup() {
  Serial.begin(9600);

  // Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  analogWrite(enA, 250);
	analogWrite(enB, 250);

  frontDir = true;
  backDir = false;

  // Turn on motors
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void loop() {

  Serial.print("Front distance = ");
	Serial.print(frontSonar.ping_cm());
	Serial.println(" cm");

  Serial.print("Back distance = ");
	Serial.print(backSonar.ping_cm());
	Serial.println(" cm");

  if(frontSonar.ping_cm() < 7 && backSonar.ping_cm() < 7) {
    stopMotors();
  }

  if(frontSonar.ping_cm() < 7 && frontDir) {
    changeDirection();
    frontDir = false;
    backDir = true;
  }

  if(backSonar.ping_cm() < 7 && backDir) {
    changeDirection();
    frontDir = true;
    backDir = false;
  }

  delay(20);
}

void changeDirection() {

  if (digitalRead(in1) == HIGH) {
    digitalWrite(in1, LOW);
	  digitalWrite(in2, HIGH);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, HIGH);
  } else {
    digitalWrite(in1, HIGH);
	  digitalWrite(in2, LOW);
	  digitalWrite(in3, HIGH);
	  digitalWrite(in4, LOW);
  }
}

void stopMotors() {

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
