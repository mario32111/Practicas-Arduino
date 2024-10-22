// Incluimos la librería para el sensor ultrasónico
#include <Ultrasonic.h>
// Definimos los pines para el sensor ultrasónico
#define TRIGGER_PIN  2
#define ECHO_PIN     3
// Definimos el pin para el LED
#define LED_PIN      13
// Creamos un objeto para el sensor ultrasónico
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
  // Inicializamos el pin del LED como salida
  pinMode(LED_PIN, OUTPUT);
  // Inicializamos la comunicación serial para ver los resultados
  Serial.begin(9600);
}
void loop() {
  // Medimos la distancia con el sensor ultrasónico en centímetros
  float distancia = ultrasonic.distanceRead(CM);
  // Mostramos la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm"); 
  // Si la distancia es menor a 50 cm, encendemos el LED
  if (distancia < 20) {
    digitalWrite(LED_PIN, HIGH); // Encendemos el LED
  } else {
    digitalWrite(LED_PIN, LOW); // Apagamos el LED
  }
  // Esperamos un breve momento antes de repetir la medición
  delay(100);
}