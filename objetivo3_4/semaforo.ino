#include "uart.h"
#include "semaforo.h"
const int led_Rojo = 13;
const int led_Amarillo = 12;
const int led_Verde = 11;
const int pinPulsador = 5;
const int pinPulsador1 = 6;
int tecla1 = 0;
int modoaux = 10;
int modoaux1 = 10;
int teclaaux = 10;
void setup() {
  Serial.begin(9600);
  pinMode(pinPulsador, INPUT_PULLUP);
  inicializarMEF(led_Rojo, led_Amarillo, led_Verde);
}

void loop() {
  actualizarMEF(pinPulsador, pinPulsador1);
  int estado1 = estado(pinPulsador, pinPulsador1);

  if (modo2() == 0) {
    if (modoaux != modo2()) {
      Serial.println("Modo Normal");
    }
  }

  else if (modo2() == 1) {
    if (modoaux != modo2()) {
      Serial.println("Modo Desconectado");
    }

  } else if (modo2() == 2) {
    if (modoaux != modo2()) {
      Serial.println("Modo Alarma");
    }
  }
  modoaux = modo2();
  if (estado1 == 0) {
    if (modoaux1 != estado1) {
      Serial.println("La MEF se encuentra en el estado ROJO");
    }
  } else if (estado1 == 1) {
    if (modoaux1 != estado1) {
      Serial.println("La MEF se encuentra en el estado AMARILLO");
    }
  } else if (estado1 == 2) {
    if (modoaux1 != estado1) {
      Serial.println("La MEF se encuentra en el estado VERDE");
    }
  } else if (estado1 == 3) {
    if (modoaux1 != estado1) {
      Serial.println("La MEF se encuentra en el estado APAGADO");
    }
  }
  modoaux1 = estado1;
  if (est_tecla1() == 0) {
    if (teclaaux != est_tecla1()) {
      Serial.println("Se ha presionado el boton 1");
    }
  } else if (est_tecla1() == 1) {
    if (teclaaux != est_tecla1()) {
      Serial.println("Se ha presionado el boton 2");
    }
  }
  teclaaux = est_tecla1();
}
