#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;

const int pinENB = 11;
const int pinIN3 = 12;
const int pinIN4 = 13;

const int speed = 255;

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);

  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
}

void avanzarA() {
  digitalWrite(pinIN1, HIGH); 
  digitalWrite(pinIN2, LOW); 
  analogWrite(pinENA, speed);
  delay(1000);
}

void avanzarB() {
  digitalWrite(pinIN3, HIGH); 
  digitalWrite(pinIN4, LOW); 
  analogWrite(pinENB, speed);
}

void retrocederA() {
  digitalWrite(pinIN1, LOW); 
  digitalWrite(pinIN2, HIGH); 
  analogWrite(pinENA, speed);
}

void retrocederB() {
  digitalWrite(pinIN3, LOW); 
  digitalWrite(pinIN4, HIGH); 
  analogWrite(pinENB, speed);
}

void detenerA() {
  digitalWrite(pinIN1, LOW); 
  digitalWrite(pinIN2, LOW); 
  analogWrite(pinENA, 0);
}

void detenerB() {
  digitalWrite(pinIN3, LOW); 
  digitalWrite(pinIN4, LOW); 
  analogWrite(pinENB, 0);
}

void loop() 
{
  if (BT.available())
  {
    char valor = BT.read();
    Serial.write(valor);
    
    if (valor == 'A') {
      avanzarA();
      avanzarB();
    }
    else if (valor == 'R') {
      retrocederA();
      retrocederB();
    }
    else if (valor == 'I') {
      detenerA();
      avanzarB();
    }
    else if (valor == 'D') {
      avanzarA();
      detenerB();
    }
    else if (valor == 'S') {
      detenerA();
      detenerB();
    }
  }

  if (Serial.available())
  {
    BT.write(Serial.read());
  }
}
