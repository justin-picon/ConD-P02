#include "uart.h"
#include "semaforo.h"

int estado(int pinPulsador, int pinPulsador1) {
  int mefValue = actualizarMEF(pinPulsador, pinPulsador1);
  
  if (mefValue >= 0 && mefValue <= 3) {
    return mefValue;
  }
}

int modo2() {
  int modo1Value = modo1();
  
  if (modo1Value >= 0 && modo1Value <= 2) {
    return modo1Value;
  }
}

int est_tecla1() {
  int teclaValue = est_tecla();
  
  if (teclaValue == 1) {
    return 0;
  } else if (teclaValue == 2) {
    return 1;
  }
}

