// encender el led de la placa mientras el boton esta presionado

// conexiones:
// una patita del boton a la patita 3
// la otra patita del boton a tierra (GND)

// incluir biblioteca
#include "Boton.h"

// crear un boton en la patita 3
Boton boton(3);

void setup()
{
  // configurar el led de la placa como salida
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // leer el boton y aplicar antirrebote
  boton.actualizar();

  // getValor() es false cuando el boton esta presionado
  if (boton.getValor() == false)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
