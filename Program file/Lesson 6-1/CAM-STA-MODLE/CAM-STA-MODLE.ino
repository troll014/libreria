#include <dummy.h>

#include <WiFi.h>

// Configuración WiFi
const char* ssid = "Ert";         // Cambia esto al nombre de tu red WiFi
const char* password = "123456789"; // Cambia esto a la contraseña de tu red WiFi

void setup() {
  // Configuración inicial del monitor serial
  Serial.begin(115200);
  Serial.println("Iniciando ESP32...");

  // Conexión al WiFi
  WiFi.begin(ssid, password);
  Serial.println("Conectando a WiFi...");

  // Espera hasta que se conecte
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConexión exitosa!");
    Serial.print("Dirección IP asignada: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nNo se pudo conectar al WiFi.");
    Serial.println("Por favor verifica el SSID y la contraseña.");
  }
}

void loop() {
  // Nada que hacer en el loop
}
