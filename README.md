# 💻 practica5esp32

> Descripcion breve y clara del proyecto: Utilizar la memoria EEPROM de un Arduino para almacenar y recuperar datos.

## Descripcion

Este proyecto utiliza la memoria EEPROM de un Arduino para almacenar y recuperar diferentes tipos de datos. Se incluyen funciones para escribir y leer cadenas, valores enteros, floats y long en la memoria EEPROM.

## Hardware Requerido

* Arduino (modelos compatibles con EEPROM)

## Software Requerido

* IDE Arduino versión 1.8.x
* Librería EEPROM instalada

## Instalacion

1. Conectar el Arduino a un ordenador mediante USB.
2. Instalar la librería EEPROM en el entorno de desarrollo: `Tools > Manage Libraries`
3. Seleccionar la placa correspondiente en `Tools > Board` y configurar el puerto serial correctamente.

## Configuracion de Pines

| Pin | Uso |
| --- | --- |
| D0 | No conectado |
| A0 | No conectado |

## Compilacion y Carga

1. Copiar el código a un nuevo proyecto en la IDE.
2. Seleccionar el puerto serial correspondiente en `Tools > Port`.
3. Verificar y subir el sketch a la placa: `Ctrl+R` y luego `Ctrl+U`.

## Uso

1. Abrir el monitor serial con una velocidad de 9600 baudios o configurada.
2. Utilizar las funciones `escribirStringEnEEPROM`, `leerStringDeEEPROM`, etc. para almacenar y recuperar datos.

## Estructura del Proyecto

* `eeprom.cpp`: archivo principal que incluye las funciones para la memoria EEPROM.
* `limpiareeprom.cpp`: ejemplo de código que limpia la memoria EEPROM.

## Troubleshooting

* Error de compilación: revisar la sintaxis y la versión de la librería EEPROM.
* Problema de puerto: asegurarse de que el puerto serial esté configurado correctamente en la IDE.
* Sketch muy grande: minimizar el código o dividirlo en archivos separados.

## Notas

* Asegurarse de no exceder los límites de memoria SRAM del Arduino.
* Evitar el uso excesivo de `String` para optimizar el uso de memoria.
* Considerar la optimización del código para el microcontrolador.