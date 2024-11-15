#define LEFT_MOTOR_EN_A 2
#define LEFT_MOTOR_IN_1 3
#define LEFT_MOTOR_IN_2 4

void setup() {
  // put your setup code here, to run once:
  pinMode(LEFT_MOTOR_EN_A, OUTPUT);
	pinMode(LEFT_MOTOR_IN_1, OUTPUT);
	pinMode(LEFT_MOTOR_IN_2, OUTPUT);

  digitalWrite(LEFT_MOTOR_IN_1, LOW);
	digitalWrite(LEFT_MOTOR_IN_2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(LEFT_MOTOR_EN_A, 255);
  digitalWrite(LEFT_MOTOR_IN_1, HIGH);
	digitalWrite(LEFT_MOTOR_IN_2, LOW);

  delay(10000);

  digitalWrite(LEFT_MOTOR_IN_1, LOW);
	digitalWrite(LEFT_MOTOR_IN_2, HIGH);

  delay(10000);

  digitalWrite(LEFT_MOTOR_IN_1, LOW);
	digitalWrite(LEFT_MOTOR_IN_2, LOW);

  delay(1000);
}
