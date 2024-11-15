#include "NewPing.h"

#define FRONT_TRIGGER_PIN 10
#define FRONT_ECHO_PIN 11

#define BACK_TRIGGER_PIN 12
#define BACK_ECHO_PIN 13

#define MAX_DISTANCE 400

#define LEFT_MOTOR_EN_A 2
#define LEFT_MOTOR_IN_1 3
#define LEFT_MOTOR_IN_2 4

#define RIGHT_MOTOR_EN_A 5
#define RIGHT_MOTOR_IN_1 6
#define RIGHT_MOTOR_IN_2 7

bool left_motor_in_value = false;
bool right_motor_in_value = false;

// NewPing setup of pins and maximum distance.
NewPing frontSonar(FRONT_TRIGGER_PIN, FRONT_ECHO_PIN, MAX_DISTANCE);
NewPing backSonar(BACK_TRIGGER_PIN, BACK_ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(LEFT_MOTOR_EN_A, OUTPUT);
	pinMode(LEFT_MOTOR_IN_1, OUTPUT);
	pinMode(LEFT_MOTOR_IN_2, OUTPUT);

  pinMode(RIGHT_MOTOR_EN_A, OUTPUT);
	pinMode(RIGHT_MOTOR_IN_1, OUTPUT);
	pinMode(RIGHT_MOTOR_IN_2, OUTPUT);

  digitalWrite(LEFT_MOTOR_IN_1, left_motor_in_value);
	digitalWrite(LEFT_MOTOR_IN_2, left_motor_in_value);

  digitalWrite(RIGHT_MOTOR_IN_1, right_motor_in_value);
	digitalWrite(RIGHT_MOTOR_IN_2, right_motor_in_value);

  analogWrite(LEFT_MOTOR_EN_A, 255);
  analogWrite(RIGHT_MOTOR_EN_A, 255);

  bool left_motor_in_value = true;
  bool right_motor_in_value = true;

  digitalWrite(RIGHT_MOTOR_IN_1, left_motor_in_value);
	digitalWrite(RIGHT_MOTOR_IN_2, !left_motor_in_value);
  digitalWrite(LEFT_MOTOR_IN_1, right_motor_in_value);
	digitalWrite(LEFT_MOTOR_IN_2, !right_motor_in_value);
}

void loop() {
  // put your main code here, to run repeatedly:


  if(frontSonar.ping_cm() < 10) {
    digitalWrite(8, HIGH);
    if(left_motor_in_value) {
      left_motor_in_value = !left_motor_in_value;
    }
    if(right_motor_in_value) {
      right_motor_in_value = !right_motor_in_value;
    }
  } else {
    digitalWrite(8, LOW);
  }

  if(backSonar.ping_cm() < 10) {
    if(!left_motor_in_value) {
      left_motor_in_value = !left_motor_in_value;
    }
    if(!right_motor_in_value) {
      right_motor_in_value = !right_motor_in_value;
    }
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }


  digitalWrite(RIGHT_MOTOR_IN_1, left_motor_in_value);
	digitalWrite(RIGHT_MOTOR_IN_2, !left_motor_in_value);
  digitalWrite(LEFT_MOTOR_IN_1, right_motor_in_value);
	digitalWrite(LEFT_MOTOR_IN_2, !right_motor_in_value);
	delay(500);
}
