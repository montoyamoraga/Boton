#include "Boton.h"

#include "Hardware.h"

Boton::Boton(uint8_t nuevaPatita)
{
    setPatita(nuevaPatita);

    BotonHardware::configurarEntradaPullup(patita);

    tiempoEntreRebotes = 50;

    // estado = SUELTO;

    valorLeidoActual = true;
    valorLeidoAnterior = true;
    
    tiempoAnteriorDesrebotar = BotonHardware::tiempoActual();
}

void Boton::setPatita(uint8_t nuevaPatita)
{
    patita = nuevaPatita;
}

void Boton::actualizar()
{
    bool lectura = BotonHardware::leerPatita(patita);

    if (lectura != valorLeidoAnterior)
    {
        tiempoAnteriorDesrebotar = BotonHardware::tiempoActual();
    }

    if (BotonHardware::tiempoActual() - tiempoAnteriorDesrebotar > tiempoEntreRebotes)
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
    // guardar la lectura cruda (no el valor estable), para que el
    // tiempo de antirrebote se reinicie solo cuando la patita cambia;
    // si se guardara valorLeidoActual, una pulsación nunca se aceptaría
    valorLeidoAnterior = lectura;
}

bool Boton::getValor() const
{
    return valorLeidoActual;
}
