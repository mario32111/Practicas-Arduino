#include <Servo.h>

Servo servoMotor;

const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;

const int pinENB = 13;
const int pinIN3 = 12;
const int pinIN4 = 11;

const int Trigger = 9;
const int Echo = 10;

int speed = 255;

void setup()
{
  Serial.begin(9600);

  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);

  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
  servoMotor.attach(3);

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
}

void girarServo(int angle) {
  servoMotor.write(angle);
  delay(500); // Esperar a que el servo se mueva
}

long medirDistancia() {
  long t, d;

  // Aseguramos que el Trigger esté en LOW antes de enviar el pulso
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);

  // Enviamos un pulso de 10 microsegundos en el Trigger
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Medimos el tiempo del pulso de retorno en el pin Echo
  t = pulseIn(Echo, HIGH);

  // Convertimos el tiempo en distancia (en centímetros)
  d = t / 58;

  return d;
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


void loop()
{
  long distancia = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 30) {
    detenerA();
    detenerB();

    girarServo(0);
    long distanciaDerecha = medirDistancia();

    girarServo(180);
    long distanciaIzquierda = medirDistancia();

    if (distanciaIzquierda > 30 && distanciaIzquierda > distanciaDerecha) {

      Serial.println("Girando a la izquierda");
      retrocederB();
      avanzarA();
      delay(600);
      detenerA();
      detenerB();
    }
    else if (distanciaDerecha > 30) {




            Serial.println("Girando a la derecha");
      avanzarB();
      retrocederA();
      delay(600);
      detenerA();
      detenerB();
    }
    else {
      Serial.println("Retrocediendo");
      retrocederA();
      retrocederB();
      delay(2000);
      detenerA();
      detenerB();

      girarServo(0);
      long distanciaDerecha = medirDistancia();

      girarServo(180);
      long distanciaIzquierda = medirDistancia();

      if (distanciaIzquierda > 30 && distanciaIzquierda > distanciaDerecha) {
        Serial.println("Girando a la izquierda");
        retrocederB();
        avanzarA();
        delay(1200);
        detenerA();
        detenerB();
        
      }
      else if (distanciaDerecha > 30) {

        Serial.println("Girando a la derecha");
        avanzarB();
        retrocederA();
        delay(1200);
        detenerA();
        detenerB();
      }


    }

    girarServo(90);
  }
  else {
    avanzarA();
    avanzarB();
  }
}
