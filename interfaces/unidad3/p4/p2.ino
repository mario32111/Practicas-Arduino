int luz;
const int F1 = 7;
const int F2 = 8;

void setup() {
  pinMode(A0, INPUT);
  pinMode(F1, OUTPUT);
  pinMode(F2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  luz= analogRead(A0);
  Serial.println(luz);
  if (luz <=100){
    digitalWrite(F1,HIGH);
    digitalWrite(F2,LOW);
  }else{
    digitalWrite(F2,HIGH);
    digitalWrite(F1,LOW);
  }
}
