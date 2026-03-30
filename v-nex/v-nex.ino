#include <Servo.h>
#define ServoPin 5

const int A1A = 8;
const int A1B = 4;
const int B1A = 7;
const int B1B = 6;

int speedCar = 180;

Servo myservo;

int angle = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);

  myservo.attach(ServoPin, 700, 2400);
  myservo.write(100);

  pinMode(2, OUTPUT);

  stop();
}

void loop() {
  stop();
  Serial.write("AAAAA");

  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);

  /*for (angle = 20; angle < 80; angle++) {
    Serial.println(angle);
    myservo.write(angle);
    delay(30);
  }

  for (angle = 20; angle > -40; angle--) {
    Serial.println(angle);
    myservo.write(angle);
    delay(30);
  }*/

  /*delay(200);
  myservo.write(140);
  delay(500);
  myservo.write(90);
  delay(100);
  myservo.write(40);
  delay(4000);*/

  forward();
  delay(2000);
  backward();
  delay(2000);
  turnLeft();
  delay(2000);
  turnRight();
  delay(2000);
  stop();
  delay(2000);
}

void backward() {
  digitalWrite(A1A, LOW);
  analogWrite(A1B, speedCar+10);
  analogWrite(B1A, speedCar);
  digitalWrite(B1B, LOW);
}

void forward() {
  analogWrite(A1A, speedCar);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, LOW);
  analogWrite(B1B, speedCar);
}

void turnLeft() {
  analogWrite(A1A, speedCar);
  digitalWrite(A1B, LOW);
  analogWrite(B1A, speedCar);
  digitalWrite(B1B, LOW);
}

void turnRight() {
  digitalWrite(A1A, LOW);
  analogWrite(A1B, speedCar);
  digitalWrite(B1A, LOW);
  analogWrite(B1B, speedCar);
}

void stop() {
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
}
