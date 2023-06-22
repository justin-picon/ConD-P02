#include "teclas.h"

typedef enum{
  BUTTON_UP, 
  BUTTON_FALLING,
  BUTTON_RISING,
  BUTTON_DOWN
} estadosMEF_t;

int contador = 0;
estadosMEF_t estadoActual;

void InicializarMEF(void){
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  estadoActual = BUTTON_UP;

  Serial.begin(9600);
}

void buttonPressed(int16_t tecla){
  Serial.print("Se ha presionado la tecla del pin: ");
  Serial.println(tecla);
}

void buttonReleased(int16_t tecla){
  contador++;
  Serial.print("Se ha liberado la tecla del pin: ");
  Serial.println(tecla);
  Serial.print("Contador de pulsaciones: ");
  Serial.println(contador);
}