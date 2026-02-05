// Proyecto de EEPROM con Arduino

#include <EEPROM.h>

// Define el tamaño de la EEPROM (ajusta según tu necesidad)
const int EEPROM_SIZE = 512;

void setup() {
  // Inicializa la comunicación serie a una velocidad de 115200 baudios
  Serial.begin(115200);

  // Comenta la inicialización de la EEPROM con el tamaño definido
  if (!EEPROM.begin(EEPROM_SIZE)) { 
    // Imprime un mensaje en la consola si hay un error al inicializar la EEPROM
    Serial.println("Error al inicializar la EEPROM");
    return;
  }

  // Escribe ceros en toda la EEPROM
  for (int i = 0; i < EEPROM_SIZE; i++) {
    // Escribe 1 en cada byte de la EEPROM
    EEPROM.write(i, 0);
  }

  // Guarda los cambios en la EEPROM
  if (EEPROM.commit()) { 
    // Imprime un mensaje en la consola si se limpia la EEPROM con éxito
    Serial.println("EEPROM limpiada exitosamente");
  } else {
    // Imprime un mensaje en la consola si hay un error al limpiar la EEPROM
    Serial.println("Error al limpiar EEPROM");
  }
}

void loop() {
  // No se necesita hacer nada en el loop (puedes agregar código aquí según sea necesario)
}