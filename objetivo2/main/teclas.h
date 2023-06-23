#include <Arduino.h>

#define SW1 3
#define SW2 8
#define RETARDO_SW1 40
#define RETARDO_SW2 40

typedef enum{
  BUTTON_UP, 
  BUTTON_FALLING,
  BUTTON_RISING,
  BUTTON_DOWN
} estadosMEF_t;

typedef struct{
  int16_t tecla;
  int16_t retardo;
  estadosMEF_t estado;
} dbn_t;

void InicializarMEF(dbn_t *dataTeclaN);
void ActualizarMEF(dbn_t *dataTeclaN);

void buttonPressed(int16_t tecla);
void buttonReleased(int16_t tecla);

void espera(int16_t milisegundos);