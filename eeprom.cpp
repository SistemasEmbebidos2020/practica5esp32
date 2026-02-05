#include <Arduino.h>

// Proyecto para ESP32: gestión de datos en memoria EEPROM y SPIFFS

#include <EEPROM.h>
#include <SPIFFS.h> // Incluir biblioteca para acceso a SPIFFS

// Escribir cadena en memoria EEPROM
void escribirStringEnEEPROM(String cadena, int direccion) {
  // Descripción: Almacena una cadena en la memoria EEPROM.
  // Parámetros: cadena (cadena a almacenar), direccion (dirección de inicio para escritura)
  int longitudCadena = cadena.length();
  for (int i = 0; i < longitudCadena; i++) {
    EEPROM.write(direccion + i, cadena[i]);
  }
  EEPROM.write(direccion + longitudCadena, '\0'); // Null-terminated string
  EEPROM.commit(); // Guardamos los cambios en la memoria EEPROM
}

// Leer cadena en memoria EEPROM
String leerStringDeEEPROM(int direccion) {
  // Descripción: Lee una cadena almacenada en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para lectura)
  String cadena = "";
  char caracter = EEPROM.read(direccion);
  int i = 0;
  while (caracter != '\0' && i < 100) {
    cadena += caracter;
    i++;
    caracter = EEPROM.read(direccion + i);
  }
  return cadena;
}

void escribirValorLongEnEEPROM(int direccion, long valor) {
  // Descripción: Almacena un valor largo en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para escritura), valor (valor a almacenar)
  int tamanoValor = sizeof(valor);
  
  for (int i = 0; i < tamanoValor; i++) {
    byte byteAEscribir = (valor >> (i * 8)) & 0xFF;
    EEPROM.write(direccion + i, byteAEscribir);
  }
  
  EEPROM.commit();
}

long leerValorLongDesdeEEPROM(int direccion) {
  // Descripción: Lee un valor largo almacenado en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para lectura)
  long valorLeido = 0;
  int tamanoValor = sizeof(valorLeido);
  
  for (int i = 0; i < tamanoValor; i++) {
    byte byteLeido = EEPROM.read(direccion + i);
    valorLeido |= (byteLeido << (i * 8));
  }
  
  return valorLeido;
}

void escribirValorFloatEnEEPROM(int direccion, float valor) {
  // Descripción: Almacena un valor flotante en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para escritura), valor (valor a almacenar)
  byte* p = (byte*)(void*)&valor;
  int tamanoValor = sizeof(valor);
  
  for (int i = 0; i < tamanoValor; i++) {
    EEPROM.write(direccion + i, *p);
    p++;
  }
  
  EEPROM.commit();
}

float leerValorFloatDesdeEEPROM(int direccion) {
  // Descripción: Lee un valor flotante almacenado en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para lectura)
  float valorLeido = 0.0;
  int tamanoValor = sizeof(valorLeido);

  byte* ptr = (byte*)&valorLeido;
  for (int i = 0; i < tamanoValor; i++) {
    *ptr = EEPROM.read(direccion + i);
    ptr++;
  }

  return valorLeido;
}

void escribirValorEnteroEnEEPROM(int direccion, int valor) {
  // Descripción: Almacena un valor entero en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para escritura), valor (valor a almacenar)
  byte* p = (byte*)(void*)&valor;
  int tamanoValor = sizeof(valor);
  
  for (int i = 0; i < tamanoValor; i++) {
    EEPROM.write(direccion + i, *p);
    p++;
  }
  
  EEPROM.commit();
}

int leerValorEnteroDesdeEEPROM(int direccion) {
  // Descripción: Lee un valor entero almacenado en la memoria EEPROM.
  // Parámetros: direccion (dirección de inicio para lectura)
  int valorLeido = 0;
  int tamanoValor = sizeof(valorLeido);
  
  for (int i = 0; i < tamanoValor; i++) {
    byte byteLeido = EEPROM.read(direccion + i);
    valorLeido |= (byteLeido << (i * 8));
  }
  
  return valorLeido;
}

// Configuración del ESP32
const int pos = 50;

void setup() {
  // Inicializar la comunicación serial a 115200 bps
  Serial.begin(115200);
  EEPROM.begin(512);  // Inicializar el tamaño de memoria EEPROM a usar

  // Verificar si la memoria SPIFFS está disponible
  if (!SPIFFS.exists()) {
    SPIFFS.begin();
  }

  // Leer cadena almacenada en la memoria EEPROM en la posición 50
  Serial.println("La lectura del espacio de la EEPROM " + String(pos) + " es " + leerStringDeEEPROM(pos));
}

void loop() {

}
