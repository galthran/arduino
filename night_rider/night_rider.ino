int i = 1;
char direction = 'R';

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void loop() {
  
  if (direction == 'R') {
    if (i < 12) {
      i = i + 1;

      if((digitalRead(i - 2) == HIGH)) {
        digitalWrite(i - 2, LOW);
      }

      digitalWrite(i - 1, HIGH);
      digitalWrite(i, HIGH);
      digitalWrite(i + 1, HIGH);

    } else {
      direction = 'L';
    }
  }

  if (direction == 'L') {
    if (i > 2) {
      i = i - 1;

      if((digitalRead(i + 2) == HIGH)) {
        digitalWrite(i + 2, LOW);
      }

      digitalWrite(i - 1, HIGH);
      digitalWrite(i, HIGH);
      digitalWrite(i + 1, HIGH);

    } else {
      direction = 'R';
    }
  }


  Serial.print("direction=");
  Serial.println(direction);
  Serial.print("i=");
  Serial.println(i);

  delay(50);

}
