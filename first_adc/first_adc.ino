int odczytanaWartosc = 0;
float napiecie = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  odczytanaWartosc = analogRead(A5);
  napiecie = odczytanaWartosc * (5.0/1024.0);
  Serial.println(napiecie);
  delay(200);
}
