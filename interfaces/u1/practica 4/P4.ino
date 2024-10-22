void setup() 
{
  for(int i=10;i<=13;i++) {
    pinMode(i,OUTPUT);
  }
}
void avanzar(int x)
{
  digitalWrite (x,HIGH);
  delay (3000);
  digitalWrite (x,LOW);
  delay(500);
  digitalWrite (x,HIGH);
  delay(500);
  digitalWrite (x,LOW);
  delay(500);
  digitalWrite (x,HIGH);
  delay(500);
  digitalWrite (x,LOW);
  delay(500);
  digitalWrite (x,HIGH);
  digitalWrite(x,LOW);
}

void precaucion(int y)
{
  digitalWrite (y, HIGH);
  delay(2000);
  digitalWrite(y,LOW);
}

void alto(int z)
{
  digitalWrite (z,HIGH);
  delay(3000);
  digitalWrite (z, LOW);
}
void loop() 
{
  avanzar (11); //avanza el pin 12
  precaucion(12);
  alto(13);
}
