#include <SPI.h>
#include <SD.h>

File myFile;

// change this to match your SD shield or module;
const int chipSelect = 10;

void setup() {
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  if(SD.exists("test.txt")) {
    SD.remove("test.txt");
  }

  writeToFile();
  delay(200);
  readFromFile();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void writeToFile() {
  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile) {
    Serial.println("Writing to test.txt file ...");
    myFile.println("testing 1, 2, 3.");
    myFile.println(millis());
    delay(100);
    myFile.println(millis());
    delay(1000);
    myFile.println(millis());
    myFile.close();
    Serial.println("done");
  } else {
    Serial.println("Error opening test.txt file");
  }
}

void readFromFile () {
  myFile = SD.open("test.txt");

  if(myFile) {
    Serial.println("test.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt file");
  }
}
