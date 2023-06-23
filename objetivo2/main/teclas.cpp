#include "teclas.h"

int contador = 0;

void InicializarMEF(dbn_t *dataTeclaN){
  pinMode(dataTeclaN->tecla, INPUT);

  dataTeclaN->estado = BUTTON_UP;

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

void espera(int16_t milisegundos){
  unsigned long tiempo_actual = 0;
  tiempo_actual = millis();
  while (millis() < tiempo_actual + milisegundos){
    
  } 
}