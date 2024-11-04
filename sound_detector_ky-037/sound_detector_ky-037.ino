int micPin = 7;
boolean micVal = LOW;

int relayPin = 13;
boolean relayState = false;


void setup() {
  pinMode(micPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  micVal = digitalRead(micPin);
  Serial.print("micVal: ");
  Serial.println(micVal);

  if (micVal == HIGH) {
    relayState = !relayState;
    digitalWrite(relayPin, relayState ? HIGH : LOW);
    delay(200);
  }


  //if (lastMicVal)

  /*if (currentMicVal != lastMicVal) {
    Serial.println("ssss");
    lastMicVal = currentMicVal;

    relayState = !relayState;
    digitalWrite(relayPin, relayState ? HIGH : LOW);
  }*/



  /*if (digitalVal == HIGH) {
    digitalWrite(ledPin, HIGH);
    relayState = !relayState;
    Serial.print("relayState: ");
    Serial.println(relayState);
		digitalWrite(relayPin, relayState ? HIGH : LOW);
  } else {
    digitalWrite(ledPin, LOW);
  }*/

  //analogVal = analogRead(analogPin);
  //Serial.print("analogVal: ");
  //Serial.println(analogVal);

  

}
