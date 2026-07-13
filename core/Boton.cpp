#include "Boton.h"

Boton::Boton(uint8_t nuevaPatita)
{
    setPatita(nuevaPatita);
    tiempoEntreRebotes = 50;
    // estado = SUELTO;
    valorLeidoActual = true;
    valorLeidoAnterior = true;
    tiempoAnteriorDesrebotar = millis();
}

void Boton::setPatita(uint8_t nuevaPatita)
{
    patita = nuevaPatita;
}

void Boton::actualizar()
{
    bool lectura = digitalRead(patita);

    if (lectura != valorLeidoAnterior)
    {
        tiempoAnteriorDesrebotar = millis();
    }

    if (millis() - tiempoAnteriorDesrebotar > tiempoEntreRebotes)
    {
        if (lectura != valorLeidoActual)
        {
            valorLeidoActual = lectura;
        }
    }

    // // si anterior = LOW y actual = LOW
    // if (!valorLeidoAnterior && !valorLeidoActual)
    // {
    //     estado = PULSADO;
    // }
    // // si anterior = LOW y actual = HIGH
    // else if (!valorLeidoAnterior && valorLeidoActual)
    // {
    //     estado = SOLTANDO;
    // }
    // // si anterior = HIGH y actual = LOW
    // else if (valorLeidoAnterior && !valorLeidoActual)
    // {
    //     estado = PULSANDO;
    // }
    // // si anterior = HIGH y actual = HIGH
    // else if (valorLeidoAnterior && valorLeidoActual)
    // {
    //     estado = SUELTO;
    // }
    // actualizar anterior con valor de actual
    valorLeidoAnterior = valorLeidoActual;
}

bool Boton::getValor()
{
    return valorLeidoActual;
}
