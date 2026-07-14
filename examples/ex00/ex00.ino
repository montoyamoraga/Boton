// include library
#include "Boton.h"

// create an instance
// using as input pin 3
Boton boton(3);

void setup()
{
  // open serial communication
  Serial.begin(9600);
}

void loop()
{
  // 
  boton.actualizar();

  Serial.println(boton.getValor());
}
