short value = 0;
float voltage = 0.0;

const int redLedPin = 2;
const int yellowLedPin = 3;
const int blueLedPin = 4;

void setup() {
  Serial.begin(9600);

  pinMode(redLedPin,OUTPUT);
  pinMode(yellowLedPin,OUTPUT);
  pinMode(blueLedPin,OUTPUT);

}

void loop() {
  value = analogRead(A0);
  voltage = value * (5.0/1024.0);

  Serial.print("Value: ");
  Serial.println(value);

  Serial.print("Voltage: ");
  Serial.println(voltage);

  if (value <= 340) {
    digitalWrite(redLedPin,HIGH);
    digitalWrite(yellowLedPin,LOW);
    digitalWrite(blueLedPin,LOW);
  } else if (value > 340 & value <= 680) {
    digitalWrite(redLedPin,LOW);
    digitalWrite(yellowLedPin,HIGH);
    digitalWrite(blueLedPin,LOW);
  } else {
    digitalWrite(redLedPin,LOW);
    digitalWrite(yellowLedPin,LOW);
    digitalWrite(blueLedPin,HIGH);
  }

  delay(1000);

}
