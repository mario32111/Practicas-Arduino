#include <SoftwareSerial.h>
SoftwareSerial BT (10,11);

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available()){
    Serial.write(BT.read());
  }

  if (Serial.available()){
    BT.write(Serial.read());
  }
}
