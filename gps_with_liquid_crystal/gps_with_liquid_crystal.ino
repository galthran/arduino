#include <LiquidCrystal.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <Bounce2.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

// GPS
const int RXPin = 2, TXPin = 3, GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);

// Button
const int buttonPin = 8;
Bounce debouncer = Bounce();
int displayMode = 0;  // 0=Location, 1=Date/Time, 2=Satellites

// Timing
unsigned long lastDisplayUpdate = 0;
const unsigned long displayInterval = 1000;  // Update every 1 second

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);

  pinMode(buttonPin, INPUT_PULLUP);
  debouncer.attach(buttonPin);
  debouncer.interval(25);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("GPS Starting...");
  delay(2000);
}

void loop() {
  // --- Feed GPS data as fast as possible ---
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  // --- Handle button press (change mode) ---
  debouncer.update();
  if (debouncer.fell()) {  // Button pressed (falling edge)
    displayMode = (displayMode + 1) % 3;  // Cycle 0 → 1 → 2 → 0
    updateDisplay();  // Immediate update on mode change
  }

  // --- Update display periodically ---
  unsigned long now = millis();
  if (now - lastDisplayUpdate >= displayInterval) {
    lastDisplayUpdate = now;
    updateDisplay();
  }
}

void updateDisplay() {
  switch (displayMode) {
    case 0: displayLocation(); break;
    case 1: displayDateTime(); break;
    case 2: displaySatellites(); break;
  }
}

void displayLocation() {
  lcd.clear();
  if (gps.location.isValid()) {
    lcd.setCursor(0, 0);
    lcd.print("Lat: ");
    lcd.print(gps.location.lat(), 6);

    lcd.setCursor(0, 1);
    lcd.print("Lng: ");
    lcd.print(gps.location.lng(), 6);
  } else {
    showSearching();
  }
}

void displayDateTime() {
  lcd.clear();

  if (gps.date.isValid() && gps.time.isValid()) {
    // Adjust to your local timezone (example: UTC+1 for Central Europe)
    int hour = gps.time.hour();
    // hour = (hour + 1) % 24;  // Uncomment and adjust for your timezone

    lcd.setCursor(0, 0);
    lcd.print("Date: ");
    lcd.print(gps.date.month());
    lcd.print("/");
    lcd.print(gps.date.day());
    lcd.print("/");
    lcd.print(gps.date.year());

    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    if (hour < 10) lcd.print("0");
    lcd.print(hour);
    lcd.print(":");
    if (gps.time.minute() < 10) lcd.print("0");
    lcd.print(gps.time.minute());
    lcd.print(":");
    if (gps.time.second() < 10) lcd.print("0");
    lcd.print(gps.time.second());
  } else {
    showSearching();
  }
}

void displaySatellites() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Satellites:");
  lcd.print(gps.satellites.value());

  lcd.setCursor(0, 1);
  if (gps.location.isValid()) {
    lcd.print("FIX ");
    if (gps.location.isUpdated()) lcd.print("NEW");
    else lcd.print("OLD");
  } else {
    lcd.print("NO FIX");
  }

  // Optional: show HDOP (accuracy)
  if (gps.hdop.isValid()) {
    lcd.setCursor(8, 1);
    lcd.print("HDOP:");
    lcd.print(gps.hdop.hdop(), 1);
  }
}

void showSearching() {
  static int dotCount = 0;
  static unsigned long lastDotUpdate = 0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Searching GPS");

  // Animated dots
  if (millis() - lastDotUpdate > 500) {
    lastDotUpdate = millis();
    dotCount = (dotCount + 1) % 4;
  }
  for (int i = 0; i < dotCount; i++) {
    lcd.print(".");
  }

  lcd.setCursor(0, 1);
  lcd.print("Sats: ");
  lcd.print(gps.satellites.value());
}