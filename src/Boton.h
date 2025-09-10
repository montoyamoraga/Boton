#ifndef BOTON_H
#define BOTON_H

#include <Arduino.h>

class Boton
{
public:
    Boton(uint8_t nuevaPatita);
    void setPatita(uint8_t nuevaPatita);
    void leer();
    bool getValor();

private:
    uint8_t patita;
    bool valorLeido;
};

#endif