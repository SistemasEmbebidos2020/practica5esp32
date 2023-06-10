#include <Arduino.h>

#include <EEPROM.h>

//escribir cadena en memoria eeprom
void escribirStringEnEEPROM(String cadena, int direccion) {
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

void escribirValorLongEnEEPROM(int direccion, long valor) {
  int tamañoValor = sizeof(valor);
  
  for (int i = 0; i < tamañoValor; i++) {
    byte byteAEscribir = (valor >> (i * 8)) & 0xFF;
    EEPROM.write(direccion + i, byteAEscribir);
  }
  
  EEPROM.commit();
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

void escribirValorFloatEnEEPROM(int direccion, float valor) {
  byte* p = (byte*)(void*)&valor;
  int tamañoValor = sizeof(valor);
  
  for (int i = 0; i < tamañoValor; i++) {
    EEPROM.write(direccion + i, *p);
    p++;
  }
  
  EEPROM.commit();
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

void escribirValorEnteroEnEEPROM(int direccion, int valor) {
  byte* p = (byte*)(void*)&valor;
  int tamañoValor = sizeof(valor);
  
  for (int i = 0; i < tamañoValor; i++) {
    EEPROM.write(direccion + i, *p);
    p++;
  }
  
  EEPROM.commit();
}

int leerValorEnteroDesdeEEPROM(int direccion) {
  int valorLeido = 0;
  int tamañoValor = sizeof(valorLeido);
  
  for (int i = 0; i < tamañoValor; i++) {
    byte byteLeido = EEPROM.read(direccion + i);
    valorLeido |= (byteLeido << (i * 8));
  }
  
  return valorLeido;
}


 int pos=50;
void setup() {
  Serial.begin(115200);
  Serial.println("la lectura del espacio de la eeprom "+String(pos)+" es "+leerStringDeEEPROM(pos));

}

void loop() {

}
