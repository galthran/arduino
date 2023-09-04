
int inPin = 7; 
int val = 0;
int counter = 0;
int currentState = 0;
int previousState = 1;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);

  val = digitalRead(inPin);
  if (val == 1 ) {
    currentState = 1;
    previousState = 0;
  }
}

void loop() {
  val = digitalRead(inPin);
  Serial.println("val=");
  Serial.println(val);
  

  /*if (val == 1 and currentState == 0) {
    currentState = 1;
    previousState = 0;
  }

  if (val == 0 and currentState == 1) {
    currentState = 0;
    previousState = 1;
  }

  if (val == 1 and currentState != previousState) {
    currentState = 1;
    previousState = 0;
    if (counter < 10) {
      counter++;
    } else {
      counter = 0;
    }
  } */
  Serial.println("counter:");
  Serial.println(counter);
  delay(500);

}
