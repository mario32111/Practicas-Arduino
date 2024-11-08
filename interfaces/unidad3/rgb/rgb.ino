const int r = 6;
const int g = 3;
const int b = 5;
const int ir = A2;
const int ig = A0;
const int ib = A1;

void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(ir, INPUT);
  pinMode(ig, INPUT);
  pinMode(ib, INPUT);
}

void loop() {
  int mr = map(analogRead(ir), 0, 1023, 0, 255);
  int mg = map(analogRead(ig), 0, 1023, 0, 255);
  int mb = map(analogRead(ib), 0, 1023, 0, 255);

  analogWrite(r, mr);
  analogWrite(g, mg);
  analogWrite(b, mb);

  Serial.print("R: ");
  Serial.println(mr);
  Serial.print("G: ");
  Serial.println(mg);
  Serial.print("B: ");
  Serial.println(mb);

  delay(200);
}
