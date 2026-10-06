// leer dos botones al mismo tiempo,
// cada uno es su propia instancia de Boton

// conexiones:
// boton a: una patita a gpio 15, la otra a tierra (GND)
// boton b: una patita a gpio 14, la otra a tierra (GND)

#include "Boton.h"

#include <stdio.h>

#include "pico/stdlib.h"

int main()
{
    // abrir comunicacion serial por usb
    stdio_init_all();

    // crear dos botones
    Boton botonA(15);
    Boton botonB(14);

    // recordar el valor de cada boton en la vuelta anterior
    bool valorAnteriorA = true;
    bool valorAnteriorB = true;

    while (true)
    {
        // actualizar cada boton
        botonA.actualizar();
        botonB.actualizar();

        bool valorActualA = botonA.getValor();
        bool valorActualB = botonB.getValor();

        // imprimir solo cuando un boton se acaba de presionar
        if (valorAnteriorA == true && valorActualA == false)
        {
            printf("boton a presionado\n");
        }

        if (valorAnteriorB == true && valorActualB == false)
        {
            printf("boton b presionado\n");
        }

        // guardar los valores para la proxima vuelta
        valorAnteriorA = valorActualA;
        valorAnteriorB = valorActualB;

        sleep_ms(1);
    }
}
