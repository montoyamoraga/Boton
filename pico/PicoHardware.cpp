#include "../Hardware.h"

#include "pico/stdlib.h"

namespace BotonHardware
{

    void configurarEntradaPullup(uint8_t patita)
    {
        gpio_init(patita);
        gpio_set_dir(patita, GPIO_IN);
        gpio_pull_up(patita);
    }

    bool leerPatita(uint8_t patita)
    {
        return gpio_get(patita);
    }

    uint32_t tiempoActual()
    {
        return to_ms_since_boot(get_absolute_time());
    }

}