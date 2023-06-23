#include "teclas.h"

void InicializarMEF(dbn_t *dataTeclaN){
  pinMode(dataTeclaN->tecla, INPUT);

  dataTeclaN->estado = BUTTON_UP;

  Serial.begin(9600);
}