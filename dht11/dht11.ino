#include <dht11.h>
dht11 DHT11;

#define DHT11PIN 2

void setup() {
  Serial.begin(9600);
  Serial.println("Program testowy DHT11");
  Serial.println();

}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
    Serial.print("OK\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.println("Błąd sumy kontrolnej\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.println("Koniec czasu oczekiwania - brak odpowiedzi\t"); 
    break;
    default: 
    Serial.println("Nieznany błąd\t"); 
    break;
  }
  Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
  Serial.print((float)DHT11.humidity, 2);
  Serial.print("\t");
  Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
  Serial.println((float)DHT11.temperature, 2);
  delay(5000);
}
