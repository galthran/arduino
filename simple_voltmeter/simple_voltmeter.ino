#include <Stepper.h>

#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int odczytanaWartosc = 0;
float napiecie = 0;

void setup() {
  lcd.begin(16, 2);
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

  lcd.setCursor(0,0); 
  lcd.clear();
  lcd.print("Voltmeter:");

  lcd.setCursor(0,1);
  lcd.print(napiecie);
  lcd.print(" V");
  delay(200);
}
