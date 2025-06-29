#define output1 7

int value = 0;
float voltage = 0;

boolean currentLightStatus = false;
boolean lightStatus = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(output1, OUTPUT);

  digitalWrite(output1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0);
  voltage = value * (5.0/1024.0);
  Serial.println(voltage);

  if(voltage < 2.0) {
    digitalWrite(output1, HIGH); 
  } else {
    digitalWrite(output1, LOW);
  }

  delay(200);
}
