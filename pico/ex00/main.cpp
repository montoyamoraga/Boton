#include "Boton.h"

#include "pico/stdlib.h"

int main()
{
    stdio_init_all();

    // configurar gpio 15
    // como entrada con pullup
    gpio_init(15);
    gpio_set_dir(15, GPIO_IN);
    gpio_pull_up(15);

    Boton boton(15);

    while (true)
    {
        boton.actualizar();

        if (!boton.getValor())
        {
            // boton presionado
        }

        sleep_ms(1);
    }
}