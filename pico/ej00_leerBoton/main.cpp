// leer un boton y mostrar por usb
// cuando se presiona y cuando se suelta

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

    // crear un boton en gpio 15,
    // la biblioteca lo configura como entrada con pull-up
    Boton boton(15);

    // recordar el valor del boton en la vuelta anterior
    bool valorAnterior = true;

    while (true)
    {
        // leer el boton y aplicar antirrebote
        boton.actualizar();

        bool valorActual = boton.getValor();

        // imprimir solo cuando el valor cambia
        if (valorActual != valorAnterior)
        {
            // getValor() es false cuando el boton esta presionado,
            // porque la patita usa la resistencia pull-up interna
            if (valorActual == false)
            {
                printf("presionado\n");
            }
            else
            {
                printf("suelto\n");
            }
        }

        // guardar el valor para la proxima vuelta
        valorAnterior = valorActual;

        sleep_ms(1);
    }
}
