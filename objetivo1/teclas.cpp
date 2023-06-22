#include "teclas.h"

typedef enum{
  BUTTON_UP, 
  BUTTON_FALLING,
  BUTTON_RISING,
  BUTTON_DOWN
} estadosMEF_t;

estadosMEF_t estadoActual;

void InicializarMEF(void){
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  estadoActual = BUTTON_UP;

  Serial.begin(9600);
}