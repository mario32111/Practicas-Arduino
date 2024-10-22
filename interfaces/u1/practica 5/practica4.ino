void setup() {
  for (int i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void contar() {
  for (int i = 0; i <= 50; i++) {
    Serial.println(i);
  }
}

void encender(int x, bool parpadear, int seconds) {

  
  digitalWrite(x, HIGH);
  delay(seconds);
  
  if (parpadear) {
    for (int i = 1; i <= 3; i++) {
      digitalWrite(x, LOW);
      delay(100);
      digitalWrite(x, HIGH);
      delay(100);
    }
  }
  
  digitalWrite(x, LOW);
}

void encender2(int x) {
  digitalWrite(x, HIGH);
}

void apagar(int x){
  digitalWrite(x, LOW);
}


void loop() {
  contar();
  
  encender2(10);
  encender(11, true, 3000); 
  encender(12, false, 2000); 
  apagar(10); 
  encender2(8);
  encender(13, false, 3000);  

  encender2(13);
  encender(8, true, 3000); 
  encender(9, false, 2000); 
  apagar(13); 
  encender2(11);
  encender(10, false, 3000); 
  
}
