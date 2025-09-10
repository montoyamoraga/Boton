#include "Boton.h"

Boton::Boton(uint8_t nuevaPatita)
{
    setPatita(nuevaPatita);
}

void Boton::setPatita(uint8_t nuevaPatita)
{
    patita = nuevaPatita;
}

void Boton::leer()
{
}

bool Boton::getValor()
{
    return valorLeido;
}