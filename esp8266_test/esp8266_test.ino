const int A1A = D8; 
const int A1B = D4;
const int B1A = D7;
const int B1B = D6;

int speedCar = 180; 

void setup() {
  Serial.begin(115200);
  
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
}

void loop() {
  Serial.println("Zatrzymanie...");
  stop();
  delay(500);
  
  Serial.println("Jazda do przodu...");
  forward();
  delay(2000);
  Serial.println("Jazda do tyłu...");
  backward();
  delay(2000);
}

void forward() {
  //LEFT engine (Motor B)
  /*analogWrite(B1A, speedCar);
  digitalWrite(B1B, LOW);*/
  
  //RIGHT engine (Motor A)
  digitalWrite(A1A, speedCar);
  analogWrite(A1B, LOW);
}

void backward() {
  //LEFT engine (Motor B)
  /*analogWrite(B1A, speedCar);
  digitalWrite(B1B, LOW);*/
  
  //RIGHT engine (Motor A)
  digitalWrite(A1A, LOW);
  analogWrite(A1B, speedCar);
}

void stop() {
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
}