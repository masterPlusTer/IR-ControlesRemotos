#include <IRremote.h>

// Define el pin del receptor IR
const int RECV_PIN = 2;

// Instancia el receptor IR
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Inicia el receptor IR
  Serial.println("Esperando señales IR...");
}

void loop() {
  // Verifica si hay datos disponibles
  if (irrecv.decode(&results)) {
    if (results.value != 0) { // Evita procesar códigos vacíos o incorrectos
      Serial.print("Código recibido: 0x");
      Serial.println(results.value, HEX);
    } else {
      Serial.println("Código recibido: Error o repetido");
    }
    irrecv.resume(); // Reinicia el receptor para leer nuevas señales
  }
}
