#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

const int pinENA = 11;
const int pinIN1 = 12;
const int pinIN2 = 13;

const int pinENB = 6;
const int pinIN3 = 7;
const int pinIN4 = 8;

const int pinF1 = 4;
const int pinF2 = 5;

const int pinBuzzer = 3; // Usar un pin PWM (por ejemplo, 6)

int speed = 255;
bool foco1Est65o = LOW;
bool foco2Estado = LOW;

const int melody[] = {
  262, 294, 330, 262, 330, 294, 262, 262, 330, 294, 262, 0
};
const int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 2
};

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

  pinMode(pinF1, OUTPUT);
  pinMode(pinF2, OUTPUT);

  pinMode(pinBuzzer, OUTPUT);
}

void avanzarA() {
  digitalWrite(pinIN1, HIGH); 
  digitalWrite(pinIN2, LOW); 
  analogWrite(pinENA, speed);
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

void toggleFocos() {
  foco1Estado = !foco1Estado;
  foco2Estado = !foco2Estado;
  
  digitalWrite(pinF1, foco1Estado);
  digitalWrite(pinF2, foco2Estado);
}

void tocarCancion() {
  for (int thisNote = 0; thisNote < 12; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    if (melody[thisNote] != 0) {
      tone(pinBuzzer, melody[thisNote], noteDuration);
    } else {
      noTone(pinBuzzer);
    }
    delay(noteDuration * 1.3); 
  }
}

void loop() 
{
  if (BT.available())
  {
    char valor = BT.read();
    Serial.write(valor);
    
    if (valor == 'A') {
        retrocederA();
        retrocederB();
    }
    else if (valor == 'R') {
            avanzarA();
      avanzarB();

    }
    else if (valor == 'I') {
      retrocederA();
      avanzarB();
    }
    else if (valor == 'D') {
      avanzarA();
      retrocederB();
    }
    else if (valor == 'S') {
      detenerA();
      detenerB();
    }
    else if (valor == 'F') {
      toggleFocos();
    }
    else if (valor == 'B') {
      tocarCancion(); // Llamamos a la función para tocar "La Cucaracha"
    } else {
      Serial.println(valor);
    }
  }

  if (Serial.available()) {
    BT.write(Serial.read());
  }
}
