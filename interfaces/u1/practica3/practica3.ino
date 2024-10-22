void setup() {
  for (int i=8; i<=12; i++){
    pinMode(i, OUTPUT);
  }
}
void loop() {
   for (int o=8; o<=12; o++){
      digitalWrite(o, HIGH);
      delay(100);
      digitalWrite(o, LOW);
      delay(100);
  }
  for (int i=12; i>=8; i--){
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
      delay(100);
  }

   for (int o=8; o<=12; o++){
      digitalWrite(o, HIGH);
      delay(100);
  }
    for (int i=12; i>=8; i--){
      digitalWrite(i, LOW);
      delay(100);
  }

   for (int o=8; o<=12; o++){
      digitalWrite(o, HIGH);
      delay(50);
      digitalWrite(o, LOW);
      delay(50);
      digitalWrite(o, HIGH);
      delay(50);
      digitalWrite(o, LOW);
      delay(50);
  }
}
