
int x = 0;
const int buttonPin = 7;
int buttonState = 0;

void setup() {
  pinMode(3, OUTPUT); //Dioda żółta
  pinMode(4, OUTPUT); //Dioda czerwona
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);  
}

void loop() {
  
    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);

    if (buttonState == 1) {
      if(x == 0) {
        x = 1;
      } else {
        x = 0;
      }
      delay(100);
    }

    if (x == 0) {
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else {
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
    }

    delay(100);
}
