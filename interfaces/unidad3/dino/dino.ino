#include <Servo.h>
Servo servoMotor;

int luz;
int angServo;
void setup() {
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  servoMotor.attach(9);

  Serial.begin(9600);
}

void girarServo(int isOb) {
  if(isOb == 0 || isOb == 1){
      servoMotor.write(65);
      delay(100); // Esperar a que el servo se mueva
      


  }else{
      servoMotor.write(90);
  }
}

void loop() {
  luz= analogRead(A0);
  angServo = map(luz, 20, 40, 0, 1);
  Serial.println(angServo);
  girarServo(angServo);
}
