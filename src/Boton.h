#ifndef BOTON_H
#define BOTON_H

#include <stdint.h>

/**
 * \~spanish
 * @brief Lee un boton conectado entre una patita y tierra, con antirrebote.
 *
 * La patita se configura como entrada con resistencia pull-up interna,
 * por eso la logica es invertida: getValor() entrega `true` cuando el
 * boton esta suelto y `false` cuando esta presionado.
 *
 * \~english
 * @brief Reads a button wired between a pin and ground, with debouncing.
 *
 * The pin is configured as an input with the internal pull-up resistor,
 * so the logic is inverted: getValor() returns `true` when the button is
 * released and `false` when it is pressed.
 */
class Boton
{
public:
    /**
     * \~spanish
     * @brief Crea el boton y configura la patita como entrada con pull-up.
     * @param nuevaPatita patita donde esta conectado el boton.
     *
     * \~english
     * @brief Creates the button and configures the pin as a pull-up input.
     * @param nuevaPatita pin the button is connected to.
     */
    explicit Boton(uint8_t nuevaPatita);

    /**
     * \~spanish
     * @brief Cambia la patita guardada, sin volver a configurarla.
     * @param nuevaPatita nueva patita.
     *
     * \~english
     * @brief Changes the stored pin, without configuring it again.
     * @param nuevaPatita new pin.
     */
    void setPatita(uint8_t nuevaPatita);

    /**
     * \~spanish
     * @brief Lee la patita y aplica el antirrebote.
     *
     * Llamalo seguido, en cada vuelta del loop. Un cambio se acepta
     * despues de 50 ms de lectura estable.
     *
     * \~english
     * @brief Reads the pin and applies debouncing.
     *
     * Call it often, on every pass of the loop. A change is accepted
     * after 50 ms of stable readings.
     */
    void actualizar();

    /**
     * \~spanish
     * @brief Ultimo valor estable del boton.
     * @return `true` si esta suelto, `false` si esta presionado.
     *
     * \~english
     * @brief Last stable value of the button.
     * @return `true` if released, `false` if pressed.
     */
    bool getValor() const;

    // enum Estado
    // {
    //     SUELTO,
    //     PULSANDO,
    //     PULSADO,
    //     SOLTANDO
    // };

private:
    uint8_t patita;
    bool valorLeidoActual;
    bool valorLeidoAnterior;
    // Estado estado;
    uint32_t tiempoAnteriorDesrebotar;
    uint32_t tiempoEntreRebotes;
};

#endif