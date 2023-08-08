#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <dht11.h>
dht11 DHT11;

#define DHT11PIN 7

void setup() {
  lcd.begin(16, 2);
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

  float humidity = DHT11.humidity;
  float temperature = DHT11.temperature;
  
  Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
  Serial.print(humidity, 2);
  Serial.print("\t");
  Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
  Serial.println(temperature, 2);

  lcd.setCursor(0,0); 
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.clear();
}
