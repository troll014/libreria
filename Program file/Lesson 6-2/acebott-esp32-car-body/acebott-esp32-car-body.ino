#include <Arduino.h>

// Pines de los motores
#define MOTOR_FRONT_LEFT_FORWARD 27
#define MOTOR_FRONT_LEFT_BACKWARD 26
#define MOTOR_FRONT_RIGHT_FORWARD 25
#define MOTOR_FRONT_RIGHT_BACKWARD 33
#define MOTOR_BACK_LEFT_FORWARD 14
#define MOTOR_BACK_LEFT_BACKWARD 12
#define MOTOR_BACK_RIGHT_FORWARD 13
#define MOTOR_BACK_RIGHT_BACKWARD 15

// Velocidad de los motores (PWM)
int speeds = 255; // Velocidad máxima (8 bits)

// Coordenadas simuladas
int simulatedX = 0;
int simulatedY = 0;
int simulatedZ = 0;

// Declaración de funciones
void stopMotors();
void moveVehicle(int x, int y, int z);
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();
void strafeRight();
void strafeLeft();
void moveForwardRight();
void moveForwardLeft();

void setup() {
  Serial.begin(115200);

  // Configuración de canales PWM para cada motor
  ledcSetup(0, 5000, 8);
  ledcAttachPin(MOTOR_FRONT_LEFT_FORWARD, 0);
  ledcSetup(1, 5000, 8);
  ledcAttachPin(MOTOR_FRONT_LEFT_BACKWARD, 1);
  ledcSetup(2, 5000, 8);
  ledcAttachPin(MOTOR_FRONT_RIGHT_FORWARD, 2);
  ledcSetup(3, 5000, 8);
  ledcAttachPin(MOTOR_FRONT_RIGHT_BACKWARD, 3);
  ledcSetup(4, 5000, 8);
  ledcAttachPin(MOTOR_BACK_LEFT_FORWARD, 4);
  ledcSetup(5, 5000, 8);
  ledcAttachPin(MOTOR_BACK_LEFT_BACKWARD, 5);
  ledcSetup(6, 5000, 8);
  ledcAttachPin(MOTOR_BACK_RIGHT_FORWARD, 6);
  ledcSetup(7, 5000, 8);
  ledcAttachPin(MOTOR_BACK_RIGHT_BACKWARD, 7);

  stopMotors(); // Detener motores al iniciar
  Serial.println("Sistema listo para simular coordenadas.");
}

void loop() {
  // Simulación de coordenadas recibidas
  // Cambia las coordenadas estáticas cada 2 segundos para simular datos
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 2000) {
    lastUpdate = millis();

    // Simulación de coordenadas
    simulatedX = random(-1, 2); // Valores entre -1 y 1
    simulatedY = random(-1, 2); // Valores entre -1 y 1
    simulatedZ = random(-1, 2); // Valores entre -1 y 1

    Serial.printf("Coordenadas simuladas: X:%d, Y:%d, Z:%d\n", simulatedX, simulatedY, simulatedZ);

    // Mover el vehículo basado en las coordenadas simuladas
    moveVehicle(simulatedX, simulatedY, simulatedZ);
  }
}

// Función para mover el vehículo
void moveVehicle(int x, int y, int z) {
  if (x > 0 && y == 0 && z == 0) {
    moveForward();
  } else if (x < 0 && y == 0 && z == 0) {
    moveBackward();
  } else if (x == 0 && y == 0 && z > 0) {
    strafeRight();
  } else if (x == 0 && y == 0 && z < 0) {
    strafeLeft();
  } else {
    stopMotors();
  }
}

// Funciones para controlar los motores
void moveForward() {
  ledcWrite(0, speeds);
  ledcWrite(2, speeds);
  ledcWrite(4, speeds);
  ledcWrite(6, speeds);

  ledcWrite(1, 0);
  ledcWrite(3, 0);
  ledcWrite(5, 0);
  ledcWrite(7, 0);

  Serial.println("Moviendo hacia adelante.");
}

void moveBackward() {
  ledcWrite(1, speeds);
  ledcWrite(3, speeds);
  ledcWrite(5, speeds);
  ledcWrite(7, speeds);

  ledcWrite(0, 0);
  ledcWrite(2, 0);
  ledcWrite(4, 0);
  ledcWrite(6, 0);

  Serial.println("Moviendo hacia atrás.");
}

void strafeRight() {
  ledcWrite(0, speeds);
  ledcWrite(3, speeds);
  ledcWrite(4, speeds);
  ledcWrite(7, speeds);

  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(5, 0);
  ledcWrite(6, 0);

  Serial.println("Moviendo hacia la derecha.");
}

void strafeLeft() {
  ledcWrite(1, speeds);
  ledcWrite(2, speeds);
  ledcWrite(5, speeds);
  ledcWrite(6, speeds);

  ledcWrite(0, 0);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
  ledcWrite(7, 0);

  Serial.println("Moviendo hacia la izquierda.");
}

void stopMotors() {
  for (int i = 0; i < 8; i++) {
    ledcWrite(i, 0);
  }
  Serial.println("Deteniendo los motores.");
}
