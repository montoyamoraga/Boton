// contar cuantas veces se presiona el boton
// y mostrar la cuenta por usb

// conexiones:
// una patita del boton a gpio 15
// la otra patita del boton a tierra (GND)

#include "Boton.h"

#include <stdio.h>

#include "pico/stdlib.h"

int main()
{
    // abrir comunicacion serial por usb
    stdio_init_all();

    // crear un boton en gpio 15
    Boton boton(15);

    // recordar el valor del boton en la vuelta anterior
    bool valorAnterior = true;

    // cuantas veces se ha presionado el boton
    int pulsaciones = 0;

    while (true)
    {
        // leer el boton y aplicar antirrebote
        boton.actualizar();

        bool valorActual = boton.getValor();

        // el boton se acaba de presionar si antes estaba suelto (true)
        // y ahora esta presionado (false)
        if (valorAnterior == true && valorActual == false)
        {
            pulsaciones = pulsaciones + 1;

            printf("pulsaciones: %d\n", pulsaciones);
        }

        // guardar el valor para la proxima vuelta
        valorAnterior = valorActual;

        sleep_ms(1);
    }
}
