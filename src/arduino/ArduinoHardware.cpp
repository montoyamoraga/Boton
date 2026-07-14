#include "./../Hardware.h"

#include <Arduino.h>

namespace BotonHardware
{

    void configurarEntradaPullup(uint8_t patita)
    {
        pinMode(patita, INPUT_PULLUP);
    }

    bool leerPatita(uint8_t patita)
    {
        return digitalRead(patita);
    }

    uint32_t tiempoActual()
    {
        return millis();
    }
}