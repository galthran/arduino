int odczytanaWartosc = 0;
float napiecie = 0;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);

}

void loop() {
  odczytanaWartosc = analogRead(A5);
  napiecie = odczytanaWartosc * (5.0/1024.0);
  Serial.println(napiecie);

  if (napiecie > 2.5) {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }
  
  delay(200);
}
