const int sensorPin = A0;
const float adcReferenceVoltage = 5.0; // napięcie odniesienia ADC (np. 5V)
const int adcResolution = 1024;        // rozdzielczość ADC (10 bitów)
const float calibrationFactor = 490.0; // <- KALIBRACJA: dostosuj, aby uzyskać prawidłowe napięcie (np. 230V)


void setup() {
  Serial.begin(9600);
}

void loop() {
  const int sampleCount = 1000;
  float sumSquares = 0;
  float offset = adcReferenceVoltage / 2.0; // napięcie odniesienia (środek sygnału AC)

  for (int i = 0; i < sampleCount; i++) {
    int adcValue = analogRead(sensorPin);
    float voltage = (adcValue * adcReferenceVoltage) / adcResolution;
    float centeredVoltage = voltage - offset;
    sumSquares += centeredVoltage * centeredVoltage;
    delayMicroseconds(100); // próbkuj co 100µs (ok. 10kHz)
  }

  float meanSquare = sumSquares / sampleCount;
  float rmsVoltage = sqrt(meanSquare);
  float acVoltage = rmsVoltage * calibrationFactor;

  Serial.print("Napięcie skuteczne (AC RMS): ");
  Serial.print(acVoltage, 2);
  Serial.println(" V");

  delay(1000);
}
