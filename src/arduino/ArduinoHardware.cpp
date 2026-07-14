#include "./../Hardware.h"

#include <Arduino.h>

namespace BotonHardware
{

    bool leerPatita(uint8_t patita)
    {
        return digitalRead(patita);
    }

    uint32_t tiempoActual()
    {
        return millis();
    }
}