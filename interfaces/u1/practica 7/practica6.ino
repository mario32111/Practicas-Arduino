void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

int up = 0;
int down = 1;

void loop() {
  // put your main code here, to run repeatedly:
  up = digitalRead(3);
  down = digitalRead(2);

  if(up == 0 ){
    digitalWrite(13, LOW);
  }

  if(down == 1){
    digitalWrite (13, HIGH);
  }
  
}
