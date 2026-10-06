# Boton

Biblioteca para leer botones con microcontroladores, con antirrebote incluido.

Funciona con placas Arduino y con placas Raspberry Pi Pico, tanto desde Arduino como desde el Pico SDK.

## Conexiones

Conecta el botón entre una patita digital y tierra (GND). No necesitas resistencia externa: la biblioteca activa la resistencia pull-up interna del microcontrolador.

Por eso la lógica es invertida:

| Estado del botón | `getValor()` |
| --- | --- |
| suelto | `true` |
| presionado | `false` |

## Uso con Arduino

Instala la biblioteca copiando esta carpeta en tu carpeta de bibliotecas de Arduino (por ejemplo `~/Documents/Arduino/libraries/Boton`), o desde Arduino IDE con *Sketch → Include Library → Add .ZIP Library...*.

```cpp
#include "Boton.h"

// boton conectado a la patita 3
Boton boton(3);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // leer el boton en cada vuelta del loop
  boton.actualizar();

  // encender el led mientras el boton esta presionado
  digitalWrite(LED_BUILTIN, !boton.getValor());
}
```

Ejemplo completo en [examples/ej00_leerBoton/](./examples/ej00_leerBoton/).

## Uso con Raspberry Pi Pico SDK

La carpeta [pico/](./pico/) tiene un proyecto CMake que compila la biblioteca y un ejemplo para Pico 2. Necesitas el [Pico SDK](https://github.com/raspberrypi/pico-sdk) instalado, o la extensión Raspberry Pi Pico de VS Code.

```bash
cd pico
mkdir build
cd build
PICO_SDK_PATH=/ruta/a/pico-sdk cmake ..
cmake --build .
```

Esto genera un archivo `.uf2` por ejemplo, como `ej00_leerBoton.uf2`. Para cargarlo, conecta la Pico manteniendo presionado el botón BOOTSEL y copia el archivo a la unidad que aparece.

Para otra placa, cambia `PICO_BOARD` en [pico/CMakeLists.txt](./pico/CMakeLists.txt) (por ejemplo `pico` para la Pico original).

Ejemplo completo en [pico/ej00_leerBoton/main.cpp](./pico/ej00_leerBoton/main.cpp).

## Ejemplos

Cada ejemplo existe para Arduino, en [examples/](./examples/), y para Pico SDK, en [pico/](./pico/). En Arduino el botón va en la patita 3, y en Pico en GPIO 15.

| Ejemplo | Qué hace |
| --- | --- |
| `ej00_leerBoton` | imprime cuando el botón se presiona y cuando se suelta |
| `ej01_encenderLed` | enciende el led de la placa mientras el botón está presionado |
| `ej02_alternarLed` | cada pulsación enciende o apaga el led |
| `ej03_contarPulsaciones` | cuenta las pulsaciones y las imprime |
| `ej04_dosBotones` | lee dos botones a la vez |

## Referencia

| Método | Descripción |
| --- | --- |
| `Boton(uint8_t patita)` | crea el botón y configura la patita como entrada con pull-up |
| `void actualizar()` | lee la patita y aplica el antirrebote; llámalo seguido, en cada vuelta del loop |
| `bool getValor()` | último valor estable: `true` suelto, `false` presionado |
| `void setPatita(uint8_t patita)` | cambia la patita guardada (no la vuelve a configurar) |

El antirrebote espera 50 ms de lectura estable antes de aceptar un cambio.

## Documentación

La documentación se genera con [Doxygen](https://www.doxygen.nl/) a partir de los comentarios en [src/](./src/), en español y en inglés, y se publica en <https://piruetasxyz.github.io/Boton/>.

Para generarla en tu computador, en español:

```bash
(cat Doxyfile; echo "OUTPUT_LANGUAGE = Spanish"; echo "HTML_OUTPUT = es") | doxygen -
```

Queda en `build/docs/es/index.html`. Para inglés, usa `English` y `en`.

Cada comentario tiene una sección `\~spanish` y una sección `\~english`. Si agregas algo público sin documentar, la generación falla.

## Cómo está organizado

El código de [src/Boton.cpp](./src/Boton.cpp) no depende de ninguna plataforma. Todo lo que toca el hardware pasa por [src/Hardware.h](./src/Hardware.h), que tiene una implementación por plataforma:

- [src/arduino/ArduinoHardware.cpp](./src/arduino/ArduinoHardware.cpp): usa `pinMode`, `digitalRead` y `millis`.
- [pico/PicoHardware.cpp](./pico/PicoHardware.cpp): usa las funciones `gpio_*` del Pico SDK.

Para agregar otra plataforma, basta con escribir otra implementación de `Hardware.h`.

## Contenido

- [.github/](./.github): flujos de trabajo que compilan los ejemplos de Arduino y de Pico, revisan la biblioteca con Arduino Lint, y publican la documentación.
- [docs/](./docs/): página principal de la documentación y página para elegir idioma.
- [examples/](./examples/): ejemplos para Arduino.
- [Doxyfile](./Doxyfile): configuración de Doxygen.
- [pico/](./pico/): proyecto CMake, implementación y ejemplo para Pico SDK.
- [src/](./src/): código de la biblioteca.
- [keywords.txt](./keywords.txt): colores de sintaxis para Arduino IDE.
- [library.properties](./library.properties): metadatos para Arduino.
- [LICENSE](./LICENSE): licencia MIT.
- [README.md](./README.md): este documento.

## Versiones

- v0.1.0: octubre 2026, arreglos para que el proyecto de [pico/](./pico/) compile con el Pico SDK.
- v0.0.3: julio 2026, refactorización para que la biblioteca sea compatible con placas Arduino y con placas Raspberry Pi Pico.

## Inspiración

Cuando estaba construyendo un secuenciador, sabía que quería que tuviera todos los sospechosos de siempre, incluyendo botones y perillas, y quería tener una biblioteca corta donde pudiera abstraer todos los comportamientos que quería para ellos.

Construí esta biblioteca, y luego quedó dormida mientras entraba a un programa de doctorado y me sumergía en electrónica y PCBs, y en enseñar programación orientada a objetos, pero sin escribir bibliotecas por un tiempo.

Ahora en 2026 supe que quería expandir mi biblioteca para que fuera compatible con las placas Raspberry Pi Pico que estoy investigando, así que agregué más carpetas y abstracciones, para hacer esta biblioteca agnóstica y poder incluirla en distintos proyectos.

## Licencia

MIT, ver [LICENSE](./LICENSE).
