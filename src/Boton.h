#ifndef BOTON_H
#define BOTON_H

#include <stdint.h>

class Boton
{
public:
    explicit Boton(uint8_t nuevaPatita);
    void setPatita(uint8_t nuevaPatita);
    void actualizar();
    bool getValor() const;

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
    uint32_t tiempoAnteriorDesrebotar;
    uint32_t tiempoEntreRebotes;
};

#endif