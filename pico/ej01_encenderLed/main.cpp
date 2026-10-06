// encender el led de la placa mientras el boton esta presionado

// conexiones:
// una patita del boton a gpio 15
// la otra patita del boton a tierra (GND)

#include "Boton.h"

#include "pico/stdlib.h"

int main()
{
    // configurar el led de la placa como salida
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    // crear un boton en gpio 15
    Boton boton(15);

    while (true)
    {
        // leer el boton y aplicar antirrebote
        boton.actualizar();

        // getValor() es false cuando el boton esta presionado
        if (boton.getValor() == false)
        {
            gpio_put(PICO_DEFAULT_LED_PIN, true);
        }
        else
        {
            gpio_put(PICO_DEFAULT_LED_PIN, false);
        }

        sleep_ms(1);
    }
}
