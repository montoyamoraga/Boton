#ifndef BOTON_H
#define BOTON_H

#include <Arduino.h>

class Boton
{
public:
    Boton(uint8_t nuevaPatita);
    void setPatita(uint8_t nuevaPatita);
    void actualizar();
    bool getValor();

    // enum Estado
    // {
    //     SUELTO,
    //     PULSANDO,
    //     PULSADO,
    //     SOLTANDO
    // };

private:
    uint8_t patita;
    bool valorLeidoActual;
    bool valorLeidoAnterior;
    // Estado estado;
    unsigned long tiempoAnteriorDesrebotar;
    unsigned long tiempoEntreRebotes;
};

#endif