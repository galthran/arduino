#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.blink();
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.write("Test");
  lcd.setCursor(0, 1);
  lcd.write("");
  lcd.noBlink();
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

}
