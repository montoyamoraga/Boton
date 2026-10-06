// leer un boton y mostrar en el monitor serial
// cuando se presiona y cuando se suelta

// conexiones:
// una patita del boton a la patita 3
// la otra patita del boton a tierra (GND)

// incluir biblioteca
#include "Boton.h"

// crear un boton en la patita 3
Boton boton(3);

// recordar el valor del boton en la vuelta anterior del loop
bool valorAnterior = true;

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

  // imprimir solo cuando el valor cambia,
  // para no llenar el monitor serial
  if (valorActual != valorAnterior)
  {
    // getValor() es false cuando el boton esta presionado,
    // porque la patita usa la resistencia pull-up interna
    if (valorActual == false)
    {
      Serial.println("presionado");
    }
    else
    {
      Serial.println("suelto");
    }
  }

  // guardar el valor para la proxima vuelta
  valorAnterior = valorActual;
}
