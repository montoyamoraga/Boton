// include library
#include "Boton.h"

// create an instance
Boton boton(3);

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  boton.actualizar();

  Serial.println(boton.getValor());
}
