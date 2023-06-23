#include <Arduino.h>

#define SW1 3
#define SW2 8
#define RETARDO 40

void InicializarMEF(void);
void ActualizarMEF(void);

void buttonPressed(int16_t tecla);
void buttonReleased(int16_t tecla);

bool espera(unsigned long intervalo);