// contar cuantas veces se presiona el boton
// y mostrar la cuenta en el monitor serial

// conexiones:
// una patita del boton a la patita 3
// la otra patita del boton a tierra (GND)

// incluir biblioteca
#include "Boton.h"

// crear un boton en la patita 3
Boton boton(3);

// recordar el valor del boton en la vuelta anterior del loop
bool valorAnterior = true;

// cuantas veces se ha presionado el boton
int pulsaciones = 0;

void setup()
{
  // abrir comunicacion serial
  Serial.begin(9600);
}

void loop()
{
  // leer el boton y aplicar antirrebote
  boton.actualizar();

  bool valorActual = boton.getValor();

  // el boton se acaba de presionar si antes estaba suelto (true)
  // y ahora esta presionado (false)
  if (valorAnterior == true && valorActual == false)
  {
    pulsaciones = pulsaciones + 1;

    Serial.print("pulsaciones: ");
    Serial.println(pulsaciones);
  }

  // guardar el valor para la proxima vuelta
  valorAnterior = valorActual;
}
