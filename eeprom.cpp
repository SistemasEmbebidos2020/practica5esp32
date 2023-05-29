#include <Arduino.h>

#include <EEPROM.h>

//escribir cadena en memoria eeprom
void escribirStringEnEEPROM(int direccion, String cadena) {
  int longitudCadena = cadena.length();
  for (int i = 0; i < longitudCadena; i++) {
    EEPROM.write(direccion + i, cadena[i]);
  }
  EEPROM.write(direccion + longitudCadena, '\0'); // Null-terminated string
  EEPROM.commit(); // Guardamos los cambios en la memoria EEPROM
}

//leer cadena en memoria eeprom
String leerStringDeEEPROM(int direccion) {
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

long leerValorLongDesdeEEPROM(int direccion) {
  long valorLeido = 0;
  int tamañoValor = sizeof(valorLeido);
  
  for (int i = 0; i < tamañoValor; i++) {
    byte byteLeido = EEPROM.read(direccion + i);
    valorLeido |= (byteLeido << (i * 8));
  }
  
  return valorLeido;
}

float leerValorFloatDesdeEEPROM(int direccion) {
  float valorLeido = 0.0;
  int tamañoValor = sizeof(valorLeido);

  byte* ptr = (byte*)&valorLeido;
  for (int i = 0; i < tamañoValor; i++) {
    *ptr = EEPROM.read(direccion + i);
    ptr++;
  }

  return valorLeido;
}

void setup() {
  Serial.begin(9600);


}

void loop() {

}
