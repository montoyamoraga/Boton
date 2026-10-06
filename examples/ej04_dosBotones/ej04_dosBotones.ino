// leer dos botones al mismo tiempo,
// cada uno es su propia instancia de Boton

// conexiones:
// boton a: una patita a la patita 3, la otra a tierra (GND)
// boton b: una patita a la patita 4, la otra a tierra (GND)

// incluir biblioteca
#include "Boton.h"

// crear dos botones
Boton botonA(3);
Boton botonB(4);

// recordar el valor de cada boton en la vuelta anterior del loop
bool valorAnteriorA = true;
bool valorAnteriorB = true;

void setup()
{
  // abrir comunicacion serial
  Serial.begin(9600);
}

void loop()
{
  // actualizar cada boton
  botonA.actualizar();
  botonB.actualizar();

  bool valorActualA = botonA.getValor();
  bool valorActualB = botonB.getValor();

  // imprimir solo cuando un boton se acaba de presionar
  if (valorAnteriorA == true && valorActualA == false)
  {
    Serial.println("boton a presionado");
  }

  if (valorAnteriorB == true && valorActualB == false)
  {
    Serial.println("boton b presionado");
  }

  // guardar los valores para la proxima vuelta
  valorAnteriorA = valorActualA;
  valorAnteriorB = valorActualB;
}
