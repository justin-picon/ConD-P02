#include "main.h"

dbn_t dataTecla1 = {SW1, RETARDO_SW1, BUTTON_UP};
dbn_t dataTecla2 = {SW2, RETARDO_SW2, BUTTON_UP};

void setup(){
  InicializarMEF(&dataTecla1);
  InicializarMEF(&dataTecla2);
}

void loop(){
  ActualizarMEF(&dataTecla1);
  ActualizarMEF(&dataTecla2);
}