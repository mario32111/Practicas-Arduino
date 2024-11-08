int luz;
int luzLed;
void setup() {
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  luz= analogRead(A0);
  Serial.println(luz);
  luzLed = map(luz, 0, 600, 0, 255);
  analogWrite(9,luzLed);
}
