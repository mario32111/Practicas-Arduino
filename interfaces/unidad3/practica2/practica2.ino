#include <Servo.h>

Servo servoMotor;

void setup() {
  // Inicializa la comunicación serial y conecta el servo al pin 9.
  Serial.begin(9600);
  servoMotor.attach(3);
}

void girarMotor(){
    for(int i = 0; i <= 180; i += 10) {
      servoMotor.write(i);
      delay(50);
  }

  for(int j = 180; j >= 0; j -= 10) {
      servoMotor.write(j); 
      delay(50);            
  }
}

void loop() {
  girarMotor();
}
