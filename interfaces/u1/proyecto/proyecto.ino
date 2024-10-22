void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

int j1 = 0;
int j2 = 0;

int ronda = 0;

int puntuacionJ1=0;
int puntuacionJ2=0;

boolean isOn= false;
void encender (){
  int r = random (5000,1000);
  delay (r);
  digitalWrite(13, HIGH);
  isOn =true;
}

void apagar(){
  digitalWrite(13, LOW);
  isOn =false;
}

void loop() {
  // put your main code here, to run repeatedly:
  j1 = digitalRead(2);
  j2 = digitalRead(3);
  //Serial.print(j1);
  //Serial.print("      |       ");
  //Serial.println(j2);
  if(isOn == true && ronda <= 3){
      if(j1 == 0 || j2 ==0){
        //Serial.print("alguien gano");
        apagar();
      }
  }else{
    ronda = ronda + 1;
    if(j1== 0){
      puntuacionJ1 += 1;
      Serial.print(puntuacionJ1);
      Serial.print("  |  ");
      Serial.println(puntuacionJ2);
      Serial.println();

    }
    if(j2 == 0){
      puntuacionJ2 += 1;
      Serial.print(puntuacionJ1);
      Serial.print("  |   ");
      Serial.println(puntuacionJ2);
      Serial.println();
    }
    encender();
  }

  
}
