#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() 
{

  if (BT.available())
  {
    char valor = BT.read();
    Serial.write(valor);
    
    if (valor == 'E') {
      digitalWrite(13, HIGH);
    }
    else {
      digitalWrite(13, LOW);
    }
  }

  if (Serial.available())
  {
    BT.write(Serial.read());
  }
}
