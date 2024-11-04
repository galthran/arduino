/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
int steps=2048;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(steps, 8, 10, 9, 11);

// the previous reading from the analog input
int previous = 0;
int button = 0;

void setup() {
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int sensorVal = digitalRead(7);
  stepper.setSpeed(5);
  stepper.step(512);

  if (digitalRead(7) == HIGH) {
    button = 1;
  }

  if (digitalRead(7) == LOW) {
    button = 0;
  }

  if (button == 1) {
    stepper.step(-512);
  } else {
    stepper.step(512);
  }

  Serial.print(" buttonz: "); 
  Serial.println(sensorVal);
}