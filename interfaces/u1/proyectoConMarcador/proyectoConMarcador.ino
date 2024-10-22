// Definir pines para los segmentos
int segmentA = 4;
int segmentB = 5;
int segmentC = 6;
int segmentD = 7;
int segmentE = 8;
int segmentF = 9;
int segmentG = 10;
int segmentDP = 11; // Pin corregido para el punto decimal

// Pines comunes para los dos displays
int common1 = 1;   // Común del primer display
int common2 = 12;  // Común del segundo display

// Variables para almacenar las puntuaciones a mostrar
int puntuacionJ1 = 0;
int puntuacionJ2 = 0;

int j1 = 0;
int j2 = 0;

int ronda = 0;

boolean isOn = false;
boolean gameReset = false; // Variable para controlar el reinicio del juego

void encender() {
  int r = random(400, 1500);  // Corregir el rango para el retardo aleatorio
  for (int i=0; i<=r; i++){
    mostrarPuntuacion2();
  }
  digitalWrite(13, HIGH);
  isOn = true;
}

void apagar() {
  digitalWrite(13, LOW);
  isOn = false;
}

void mostrarPuntuacion2(){
  Serial.print("m");
  // Mostrar el número en el primer display (J2)
  digitalWrite(common1, LOW);   
  digitalWrite(common2, HIGH);  
  displayNumber(puntuacionJ2); 
  delay(3);                   

  // Mostrar el número en el segundo display (J1)
  digitalWrite(common1, HIGH);
  digitalWrite(common2, LOW); 
  displayNumber(puntuacionJ1);
  delay(3);
}

void mostrarPuntuacion(){
  Serial.print("m");
  // Mostrar el número en el primer display (J2)
  digitalWrite(common1, LOW);   
  digitalWrite(common2, HIGH);
  displayNumber(puntuacionJ2);
  delay(7);                   

  // Mostrar el número en el segundo display (J1)
  digitalWrite(common1, HIGH); 
  digitalWrite(common2, LOW);
  displayNumber(puntuacionJ1); 
  delay(7);
}

void setup() {
  // Configurar los pines de los segmentos como salidas
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);

  // Configurar los pines comunes como salidas
  pinMode(common1, OUTPUT);
  pinMode(common2, OUTPUT);

  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (gameReset) {
    // Esperar 10 segundos antes de reiniciar
    for(int i=0; i<=714; i++){
      mostrarPuntuacion2();
    }
    // Reiniciar las variables
    puntuacionJ1 = 0;
    puntuacionJ2 = 0;
    ronda = 0;
    gameReset = false;
    encender(); // Reiniciar el juego
  }

  mostrarPuntuacion();
  // Leer los botones
  j1 = digitalRead(2);
  j2 = digitalRead(3);

  // Comportamiento si la luz está encendida
  if ((isOn == true) && (j1 == 1 || j2 == 1)) {
    if (j1 == 1) {
      ronda = ronda + 1;
      puntuacionJ1 += 1;
    }
    if (j2 == 1) {
      ronda = ronda + 1;
      puntuacionJ2 += 1;
    }
    Serial.println("");
    Serial.print(puntuacionJ1);
    Serial.print("    |     ");
    Serial.println(puntuacionJ2);

    apagar();
    
  } else {
    if((isOn == false) && (j1 == 0 && j2 == 0)) {
      encender();
    }
  }

  // Verificar si la ronda es mayor o igual a 3 para reiniciar el juego
  if (ronda >= 3 ||(puntuacionJ1 == 2 || puntuacionJ2 == 2)) {
    gameReset = true;
  }
}

// Función para encender los segmentos y mostrar un número
void displayNumber(int num) {
  // Apagar todos los segmentos antes de encender los necesarios
  clearSegments();

  switch (num) {
    case 0:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      break;
    case 1:
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentD, HIGH);
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
  }
}

// Función para apagar todos los segmentos
void clearSegments() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDP, LOW);
}
