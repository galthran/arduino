#include <LiquidCrystal.h> 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte mychar[8] = {
  0b00000, // 0b - prefix, 0 point is not lighting, 1 point is lighting
  0b00000,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b00000
};

byte temperatoreChar[8] = {
  0b00010, 
  0b00101,
  0b00010,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, heart);
  lcd.createChar(1, mychar);
  lcd.createChar(2, temperatoreChar);
  
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.blink();
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.write("Test");
  lcd.setCursor(6, 0);
  lcd.write(byte(0));
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(10, 0);
  lcd.write(byte(2));
  lcd.setCursor(11, 0);
  lcd.write("C");
  lcd.noBlink();
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

}
