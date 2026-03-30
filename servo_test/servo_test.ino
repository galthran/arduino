#include <Servo.h>
#include <Bounce2.h>

const int buttonRightPin = 2;
const int buttonLeftPin  = 3;
const int servoPin = 9;

Servo servo;

Bounce bounceRight = Bounce();
Bounce bounceLeft  = Bounce();

int angle = 90;

unsigned long lastMove = 0;
const int interval = 10;

void setup() {
  servo.attach(servoPin);

  bounceRight.attach(buttonRightPin, INPUT_PULLUP);
  bounceRight.interval(5);

  bounceLeft.attach(buttonLeftPin, INPUT_PULLUP);
  bounceLeft.interval(5);

  Serial.begin(9600);
}

void loop() {
  bounceRight.update();
  bounceLeft.update();

  bool rightPressed = (bounceRight.read() == LOW);
  bool leftPressed  = (bounceLeft.read() == LOW);

  int direction = 0;

  if (rightPressed && !leftPressed) {
    direction = 1;   // w prawo
  } 
  else if (leftPressed && !rightPressed) {
    direction = -1;  // w lewo
  } 
  else {
    direction = 0;   // stop (oba lub żaden)
  }

  // ruch serwa
  if (millis() - lastMove > interval) {
    lastMove = millis();

    angle += direction;

    // ograniczenia
    if (angle > 180) angle = 180;
    if (angle < 0)   angle = 0;

    servo.write(angle);
  }
}