// cada vez que presionas el boton, el led cambia
// de apagado a encendido, o de encendido a apagado

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

    // recordar el valor del boton en la vuelta anterior
    bool valorAnterior = true;

    // recordar si el led esta encendido
    bool ledEncendido = false;

    while (true)
    {
        // leer el boton y aplicar antirrebote
        boton.actualizar();

        bool valorActual = boton.getValor();

        // el boton se acaba de presionar si antes estaba suelto (true)
        // y ahora esta presionado (false)
        if (valorAnterior == true && valorActual == false)
        {
            // cambiar el estado del led
            ledEncendido = !ledEncendido;
            gpio_put(PICO_DEFAULT_LED_PIN, ledEncendido);
        }

        // guardar el valor para la proxima vuelta
        valorAnterior = valorActual;

        sleep_ms(1);
    }
}
