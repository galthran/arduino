int counter = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println(counter); //Wysłanie wartości zmiennej licznik
  counter = counter + 1; //Zwiększenie licznika o 1
  delay(100); //Opóźnienie, aby efekt był lepiej widoczny
}
