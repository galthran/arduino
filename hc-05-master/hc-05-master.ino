#define ledPin 9

int state = 0;
int potValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400);
}

void loop() {
  if (Serial.available() > 0){
    Serial.println("Serial.available");
    state = Serial.read();
  }
  Serial.println(state);

  if (state == '1') {
    digitalWrite(ledPin, HIGH);
    state = 0;
  } else if (state == '0') {
    digitalWrite(ledPin, LOW);
    state = 0;
  }

//  potValue = analogRead(A0);
//  int potValueMapper = map(potValue, 0, 1023, 0, 255);
//  Serial.println(potValueMapper);
//  Serial.write(potValueMapper);
  delay(1000);
}
