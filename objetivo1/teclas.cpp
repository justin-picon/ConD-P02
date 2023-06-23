#include "teclas.h"

typedef enum{
  BUTTON_UP, 
  BUTTON_FALLING,
  BUTTON_RISING,
  BUTTON_DOWN
} estadosMEF_t;

int contador = 0;
estadosMEF_t estadoActual;
unsigned long tiempoAnterior = 0;

void InicializarMEF(void){
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  estadoActual = BUTTON_UP;

  Serial.begin(9600);
}

void ActualizarMEF(void){
  switch (estadoActual){
    case BUTTON_UP:
      if(digitalRead(SW1) == LOW){
        estadoActual = BUTTON_FALLING;
      }
      break;
    case BUTTON_FALLING:
      if(espera(RETARDO)){
        if(digitalRead(SW1) ==  LOW){
          estadoActual = BUTTON_DOWN;
          buttonPressed(SW1);
        }else{
          estadoActual = BUTTON_UP;
        }
      }
      break;
    case BUTTON_RISING:
      if (espera(RETARDO)){
        if(digitalRead(SW1) == HIGH){
          estadoActual = BUTTON_UP;
          buttonReleased(SW1);
        }else{
          estadoActual = BUTTON_DOWN;
        }
      }
      break;
    case BUTTON_DOWN:
      if(digitalRead(SW1) == HIGH){
        estadoActual = BUTTON_RISING;
      }
      break;
    default:
      InicializarMEF();
      break;
  }
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

bool espera(unsigned long intervalo){
  unsigned long milisegundos = millis();
  if (milisegundos - tiempoAnterior >= intervalo){
    tiempoAnterior = milisegundos;
    return true;
  }
  return false;
}