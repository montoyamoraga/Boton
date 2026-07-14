#ifndef BOTON_HARDWARE_H
#define BOTON_HARDWARE_H

#include <stdint.h>

namespace BotonHardware
{

    void configurarEntradaPullup(uint8_t patita);

    bool leerPatita(uint8_t patita);

    uint32_t tiempoActual();
}

#endif