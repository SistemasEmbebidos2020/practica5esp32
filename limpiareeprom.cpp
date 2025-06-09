#include <EEPROM.h>

const int EEPROM_SIZE = 512; // Define el tamaño de la EEPROM (ajusta según tu necesidad)

void setup() {
  Serial.begin(115200);
  
  // Inicia la EEPROM con el tamaño definido
  if (!EEPROM.begin(EEPROM_SIZE)) {
    Serial.println("Error al inicializar la EEPROM");
    return;
  }

  // Escribe ceros en toda la EEPROM
  for (int i = 0; i < EEPROM_SIZE; i++) {
    EEPROM.write(i, 1); // Escribe 1 en cada byte de la EEPROM
  }

  // Guarda los cambios
  if (EEPROM.commit()) {
    Serial.println("EEPROM limpiada exitosamente");
  } else {
    Serial.println("Error al limpiar EEPROM");
  }

}

void loop() {
  // No se necesita hacer nada en el loop
}
