#include <Servo.h>
#include <Ultrasonic.h>
#include <NewPing.h>
#include <LiquidCrystal.h>
#include <DHT.h>

// Definiciones de pines y constantes
#define TRIGGER_PIN 7  // Pin para el disparo del sensor ultrasónico
#define ECHO_PIN 6     // Pin para la recepción del eco del sensor ultrasónico
#define MAX_DISTANCE 200 // Distancia máxima en cm para el sensor ultrasónico

#define DHTPIN 6       // Pin de datos para el sensor DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT

#define LED_PIN1 13    // Pin para el primer LED
#define LED_PIN2 12    // Pin para el segundo LED
#define SERVO_PIN 11   // Pin para el servomotor

// Creación de objetos para los componentes
Servo myservo; // Objeto para controlar el servomotor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Objeto para el sensor ultrasónico
DHT dht(DHTPIN, DHTTYPE); // Objeto para el sensor DHT

LiquidCrystal lcd(5, 4, 8, 9, 3, 2); // Objeto para controlar la pantalla LCD

const int sensorPin = A0; // Pin analógico para el sensor de luz
int sensorValue = 0; // Variable para almacenar el valor del sensor de luz

// Configuración inicial del sistema
void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 bps
  myservo.attach(SERVO_PIN); // Asocia el servomotor al pin definido
  dht.begin(); // Inicializa el sensor DHT
  lcd.begin(16, 2); // Inicializa la pantalla LCD con 16 columnas y 2 filas
  pinMode(LED_PIN1, OUTPUT); // Configura el primer LED como salida
  pinMode(LED_PIN2, OUTPUT); // Configura el segundo LED como salida
}
// Bucle principal del sistema
void loop() {
  sensorValue = analogRead(sensorPin); // Lee el valor del sensor de luz
  float temperature = dht.readTemperature(); // Lee la temperatura del sensor DHT

  // Verifica si la lectura del sensor DHT es válida
  if (isnan(temperature)) {
    Serial.println("Error al leer el sensor DHT11"); // Imprime un mensaje de error en la consola serial
    lcd.setCursor(0, 1); // Posiciona el cursor en la segunda fila de la pantalla LCD
    lcd.print("Temp: Error"); // Muestra un mensaje de error en la pantalla LCD
  } else {
    lcd.clear(); // Limpia la pantalla LCD
    lcd.setCursor(0, 0); // Posiciona el cursor en la primera fila
    lcd.print("Luz: "); // Muestra el texto "Luz: "
    lcd.print(sensorValue); // Muestra el valor del sensor de luz
    lcd.setCursor(0, 1); // Posiciona el cursor en la segunda fila
    lcd.print("Temp: "); // Muestra el texto "Temp: "
    lcd.print(temperature); // Muestra la temperatura leída
    lcd.print(" C"); // Muestra la unidad de temperatura
  }

  // Control del primer LED basado en el valor del sensor de luz
  if(sensorValue >= 500){
    digitalWrite(LED_PIN1, HIGH); // Enciende el primer LED si el valor del sensor de luz es mayor o igual a 500
  } else {
    digitalWrite(LED_PIN1, LOW); // Apaga el primer LED si el valor del sensor de luz es menor a 500
  }

  // Control del segundo LED basado en la temperatura
  if(temperature >= 30){
    digitalWrite(LED_PIN2, HIGH); // Enciende el segundo LED si la temperatura es mayor o igual a 30°C
  } else {
    digitalWrite(LED_PIN2, LOW); // Apaga el segundo LED si la temperatura es menor a 30°C
  }

  // Control del servomotor basado en el estado de los LEDs
  if (digitalRead(LED_PIN1) == HIGH || digitalRead(LED_PIN2) == HIGH) {
    myservo.write(90); // Mueve el servomotor a 90 grados si cualquiera de los LEDs está encendido
  } else {
    myservo.write(0); // Mueve el servomotor a 0 grados si ambos LEDs están apagados
  }

  // Aumenta la velocidad del servomotor si ambos LEDs están encendidos
  if (digitalRead(LED_PIN1) == HIGH && digitalRead(LED_PIN2) == HIGH) {
    myservo.write(180); // Mueve el servomotor a 180 grados si ambos LEDs están encendidos
  }

  delay(1000); // Espera 1 segundo antes de repetir el bucle
}


