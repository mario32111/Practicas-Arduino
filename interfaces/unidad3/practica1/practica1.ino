const int Trigger = 9;
const int Echo = 10;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
}

void loop() {
  long t;
  long d;
  
  // Aseguramos que el Trigger esté en LOW antes de enviar el pulso
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  
  // Enviamos un pulso de 10 microsegundos en el Trigger
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Medimos el tiempo del pulso de retorno en el pin Echo
  t = pulseIn(Echo, HIGH);
  
  // Convertimos el tiempo en distancia (en centímetros)
  d = t / 58;

  // Imprimimos la distancia en centímetros
  Serial.print(d);
  Serial.println(" cm");
  
  // Pausa para evitar lecturas muy seguidas
  delay(200);
}
