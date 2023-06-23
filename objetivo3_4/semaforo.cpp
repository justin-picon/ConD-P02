#include "semaforo.h"
typedef enum {
  ROJO,
  AMARILLO,
  VERDE,
  APAGADO
} EstadosNormal;
// Definición de los estados de velocidad
typedef enum {
  NORMAL,
  DOBLE,
  MITAD
} Velocidad;
typedef enum {
  NORMALL,
  DESCONECTADO,
  ALARMA
} Modos;
// Variables para el control de velocidad
Velocidad velocidadActual;
EstadosNormal estadoActualNormal;
Modos modo;

unsigned long tiempoAnterior;
unsigned long intervalo;
unsigned long intervalo1;
unsigned long intervalo2;
unsigned long intervalo3;
int tecla = 0;

// Variable para controlar el estado del pulsador

int modo1(void) {
  return modo;
}
int est_tecla(void) {
  return tecla;
}
int inicializarMEF(int led_Rojo, int led_Amarillo, int led_Verde) {
  estadoActualNormal = VERDE;
  velocidadActual = NORMAL;
  modo = NORMALL;

  // Configurar los pines del semáforo como salidas
  pinMode(led_Rojo, OUTPUT);      // Pin del LED rojo
  pinMode(led_Amarillo, OUTPUT);  // Pin del LED amarillo
  pinMode(led_Verde, OUTPUT);     // Pin del LED verde
  intervalo1 = 3000;
  intervalo2 = 500;
  intervalo3 = 2000;
}
int actualizarMEF(int pinPulsador, int pinPulsador1) {
  unsigned long tiempoActual = millis();  // Obtener el tiempo actual
                                          // Verificar si se ha pulsado el botón para cambiar la velocidad
  if (digitalRead(pinPulsador1) == HIGH) {
    delay(25);  // Retardo para evitar fluctuaciones en la lectura del botón

    if (digitalRead(pinPulsador1) == LOW) {
      tecla = 1;

      // Cambiar la velocidad según el estado actual
      switch (modo) {

        case NORMALL:

          modo = DESCONECTADO;
          estadoActualNormal = APAGADO;
          break;
        case DESCONECTADO:

          modo = ALARMA;
          estadoActualNormal = APAGADO;
          break;
        case ALARMA:

          modo = NORMALL;
          estadoActualNormal = VERDE;
          break;
      }
    }
  }
  if (digitalRead(pinPulsador) == HIGH) {
    delay(25);  // Retardo para evitar fluctuaciones en la lectura del botón

    if (digitalRead(pinPulsador) == LOW) {
      tecla = 2;
      // Cambiar la velocidad según el estado actual
      switch (velocidadActual) {
        case NORMAL:
          velocidadActual = DOBLE;
          intervalo1 = 6000;
          intervalo2 = 1000;
          intervalo3 = 4000;
          break;
        case DOBLE:
          velocidadActual = MITAD;
          intervalo1 = 1500;
          intervalo2 = 250;
          intervalo3 = 1000;
          break;
        case MITAD:
          velocidadActual = NORMAL;
          intervalo1 = 3000;
          intervalo2 = 500;
          intervalo3 = 2000;
          break;
      }
    }
  }
  if (modo == 0) {
    switch (estadoActualNormal) {
      case ROJO:
        // Encender el LED rojo
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);

        if (tiempoActual - tiempoAnterior >= intervalo3) {
          estadoActualNormal = VERDE;     // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;

      case VERDE:
        // Encender el LED verde
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);

        if (tiempoActual - tiempoAnterior >= intervalo1) {
          estadoActualNormal = AMARILLO;  // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;

      case AMARILLO:
        // Encender el LED amarillo-verde
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);

        if (tiempoActual - tiempoAnterior >= intervalo2) {
          estadoActualNormal = ROJO;      // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;
    }
    return estadoActualNormal;
  }
  if (modo == 1) {

    switch (estadoActualNormal) {
      case AMARILLO:
        // Encender el LED rojo
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);

        if (tiempoActual - tiempoAnterior >= intervalo2) {
          estadoActualNormal = APAGADO;   // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;

      case APAGADO:
        // Encender el LED verde
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);

        if (tiempoActual - tiempoAnterior >= intervalo2) {
          estadoActualNormal = AMARILLO;  // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;
    }
    return estadoActualNormal;
  }
  if (modo == 2) {

    switch (estadoActualNormal) {
      case ROJO:
        // Encender el LED rojo
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);

        if (tiempoActual - tiempoAnterior >= intervalo3 / 2) {
          estadoActualNormal = APAGADO;   // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;

      case APAGADO:
        // Encender el LED verde
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);

        if (tiempoActual - tiempoAnterior >= intervalo3 / 2) {
          estadoActualNormal = ROJO;      // Cambiar al siguiente estado
          tiempoAnterior = tiempoActual;  // Actualizar el tiempo anterior
        }
        break;
    }
    return estadoActualNormal;
  }
}