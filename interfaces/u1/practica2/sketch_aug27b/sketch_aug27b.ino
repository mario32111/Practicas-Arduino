void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(3000);

  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(3000);


  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(11, HIG H);
  delay(3000);
}
