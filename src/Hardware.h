#ifndef BOTON_HARDWARE_H
#define BOTON_HARDWARE_H

#include <stdint.h>

/**
 * \~spanish
 * @brief Funciones que tocan el hardware, con una implementacion por plataforma.
 *
 * Boton.cpp solo usa estas funciones, asi no depende de ninguna plataforma.
 * Las implementaciones estan en src/arduino/ArduinoHardware.cpp y
 * pico/PicoHardware.cpp.
 *
 * \~english
 * @brief Functions that touch the hardware, with one implementation per platform.
 *
 * Boton.cpp only uses these functions, so it does not depend on any platform.
 * The implementations are in src/arduino/ArduinoHardware.cpp and
 * pico/PicoHardware.cpp.
 */
namespace BotonHardware
{

    /**
     * \~spanish
     * @brief Configura la patita como entrada con resistencia pull-up interna.
     * @param patita patita a configurar.
     *
     * \~english
     * @brief Configures the pin as an input with the internal pull-up resistor.
     * @param patita pin to configure.
     */
    void configurarEntradaPullup(uint8_t patita);

    /**
     * \~spanish
     * @brief Lee el valor digital de la patita.
     * @param patita patita a leer.
     * @return `true` si esta en alto, `false` si esta en bajo.
     *
     * \~english
     * @brief Reads the digital value of the pin.
     * @param patita pin to read.
     * @return `true` if high, `false` if low.
     */
    bool leerPatita(uint8_t patita);

    /**
     * \~spanish
     * @brief Tiempo desde que partio el microcontrolador.
     * @return tiempo en milisegundos.
     *
     * \~english
     * @brief Time since the microcontroller started.
     * @return time in milliseconds.
     */
    uint32_t tiempoActual();
}

#endif