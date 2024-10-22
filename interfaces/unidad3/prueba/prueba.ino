#include <Servo.h>

Servo servoMotor;

// Definición de pines para los motores
const int pinENA = 6;
const int pinIN1 = 7;
const int pinIN2 = 8;

const int pinENB = 13;
const int pinIN3 = 11;
const int pinIN4 = 12;

// Definición de pines para el sensor ultrasónico
const int Trigger = 9;
const int Echo = 10;

int speed = 255; // Velocidad máxima para los motores

void setup() {
  Serial.begin(9600);
  
  // Configuración de los pines de los motores como salida
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);

  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
  
  // Configuración del servo motor
  servoMotor.attach(3);

  // Configuración de los pines del sensor ultrasónico
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
}

// Funciones para girar el servo
void girarServo(int angle) {
  servoMotor.write(angle);
  delay(500); // Esperar a que el servo se mueva
}

// Función para medir la distancia con el sensor ultrasónico
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

// Funciones para controlar el motor A
void avanzarA() {
  digitalWrite(pinIN1, HIGH); 
  digitalWrite(pinIN2, LOW); 
  analogWrite(pinENA, speed);
}

void retrocederA() {
  digitalWrite(pinIN1, LOW); 
  digitalWrite(pinIN2, HIGH); 
  analogWrite(pinENA, speed);
}

void detenerA() {
  digitalWrite(pinIN1, LOW); 
  digitalWrite(pinIN2, LOW); 
  analogWrite(pinENA, 0);
}

// Funciones para controlar el motor B
void avanzarB() {
  digitalWrite(pinIN3, HIGH); 
  digitalWrite(pinIN4, LOW); 
  analogWrite(pinENB, speed);
}

void retrocederB() {
  digitalWrite(pinIN3, LOW); 
  digitalWrite(pinIN4, HIGH); 
  analogWrite(pinENB, speed);
}

void detenerB() {   
  digitalWrite(pinIN3, LOW); 
  digitalWrite(pinIN4, LOW); 
  analogWrite(pinENB, 0);
}

// Función principal de bucle
void loop() {
  avanzarA();     // Avanzar motor A
  avanzarB();     // Avanzar motor B
  delay(2000);    // Esperar 2 segundos

  detenerA();     // Detener motor A
  detenerB();     // Detener motor B
  delay(2000);    // Esperar 2 segundos

  retrocederA();  // Retroceder motor A
  retrocederB();  // Retroceder motor B
  delay(2000);    // Esperar 2 segundos

  detenerA();     // Detener motor A
  detenerB();     // Detener motor B
  delay(2000);    // Esperar 2 segundos
}
