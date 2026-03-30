#define button 8

int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  Serial.begin(38400);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    Serial.println("HIGH");
    Serial.write('1'); // Sends '1' to the master to turn on LED
  } else {
    Serial.println("LOW");
    Serial.write('0');
  }  
}
