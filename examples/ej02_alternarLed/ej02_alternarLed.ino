// cada vez que presionas el boton, el led cambia
// de apagado a encendido, o de encendido a apagado

// conexiones:
// una patita del boton a la patita 3
// la otra patita del boton a tierra (GND)

// incluir biblioteca
#include "Boton.h"

// crear un boton en la patita 3
Boton boton(3);

// recordar el valor del boton en la vuelta anterior del loop
bool valorAnterior = true;

// recordar si el led esta encendido
bool ledEncendido = false;

void setup()
{
  // configurar el led de la placa como salida
  pinMode(LED_BUILTIN, OUTPUT);
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
    // cambiar el estado del led
    ledEncendido = !ledEncendido;
    digitalWrite(LED_BUILTIN, ledEncendido);
  }

  // guardar el valor para la proxima vuelta
  valorAnterior = valorActual;
}
