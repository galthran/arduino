#include <Servo.h>

int potPin = 0;
int servoPin = 9;
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  int reading = analogRead(potPin);
  Serial.print("reading: ");
  Serial.println(reading);

  int angle = map(reading, 0, 1023, 0, 270);
  Serial.print("angle: ");
  Serial.println(angle);

  servo.write(angle);

  delay(200);
}
