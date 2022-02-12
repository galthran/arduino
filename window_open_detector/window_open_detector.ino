#define diodaCzerwona 8
#define diodaNiebieska 9
#define czujnikOkna 10

void setup() {
  Serial.begin(9600);
  
  pinMode(diodaCzerwona, OUTPUT); //Wyjście diody zielonej
  pinMode(diodaNiebieska, OUTPUT); //Wyjście diody czerwonej
  pinMode(czujnikOkna, INPUT_PULLUP); //Przycisk
  
  digitalWrite(diodaCzerwona, LOW); 
  digitalWrite(diodaNiebieska, LOW);

}

void loop() {

  if (digitalRead(czujnikOkna) == LOW) {
    digitalWrite(diodaCzerwona, HIGH); 
    digitalWrite(diodaNiebieska, LOW);
  } else {
    digitalWrite(diodaCzerwona, LOW); 
    digitalWrite(diodaNiebieska, HIGH);
    Serial.println("Uwaga! Alarm! Okno nie jest zamkniete!");

    while (digitalRead(czujnikOkna) == HIGH) {
      //Zatrzymujemy się w pustej pętli do ponownego zamknięcia okna
      delay(25); //W pętli wprowadzamy małe opóźnienie 25ms, aby niwelować zakłócenia
    }
  }
  
}
