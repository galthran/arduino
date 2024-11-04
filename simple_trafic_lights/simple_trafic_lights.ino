

void setup() {
  pinMode(2, OUTPUT); //Dioda zielona
  pinMode(3, OUTPUT); //Dioda żółta
  pinMode(4, OUTPUT); //Dioda czerwona


  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);

  delay(2000);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);

  delay(2000);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  delay(2000);
}
