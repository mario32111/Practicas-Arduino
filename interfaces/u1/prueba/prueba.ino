// Definir pines para los segmentos
int segmentA = 4;
int segmentB = 5;
int segmentC = 6;
int segmentD = 7;
int segmentE = 8;
int segmentF = 9;
int segmentG = 10;
int segmentDP = 11; // Punto decimal, opcional

// Pines comunes para los dos displays
int common1 = 1;   // Común del primer display
int common2 = 12;  // Común del segundo display

// Variable para almacenar los números a mostrar
int display1Value = 3;
int display2Value = 3;

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
  pinMode(13, OUTPUT);

}

void loop() {
  // Mostrar el número en el primer display
  digitalWrite(13, HIGH);
  digitalWrite(common1, LOW);   // Activar primer display (cátodo común: LOW, ánodo común: HIGH)
  digitalWrite(common2, HIGH);  // Desactivar segundo display
  displayNumber(display1Value); // Mostrar número en el primer display
  delay(13);                     // Pausa breve para multiplexación

  // Mostrar el número en el segundo display
  digitalWrite(common1, HIGH);  // Desactivar primer display
  digitalWrite(common2, LOW);   // Activar segundo display
  displayNumber(display2Value); // Mostrar número en el segundo display
  delay(13);                     // Pausa breve para multiplexación
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
