/*!
 *  @file LED.h
 *
 * 	Basic LED Information and functions
 *
 *	GPL license (see license)
 */
#include "../pch.h"
#include "BasicRGB.h"

namespace BasicRGB
{

    /*!
     * @brief Sets up LED pinmodes
     */
    void BasicRGB::ledSetup()
    {
        turnOffAll();

        // Init LED
        pinMode(RLED, OUTPUT);
        pinMode(GLED, OUTPUT);
        pinMode(BLED, OUTPUT);
    }
    /*!
     * @brief Turns off all LEDs
     */
    void BasicRGB::turnOffAll()
    {
        digitalWrite(RLED, OFF);
        digitalWrite(GLED, OFF);
        digitalWrite(BLED, OFF);
    }

    /*!
     * @brief Turns On Red LED
     */
    void BasicRGB::redOn() { digitalWrite(RLED, ON); };

    /*!
     * @brief Turns Off Red LED
     */
    void BasicRGB::redOff() { digitalWrite(RLED, OFF); };

    /*!
     * @brief Turns On Green LED
     */
    void BasicRGB::greenOn() { digitalWrite(GLED, ON); };

    /*!
     * @bgreenf Turns Off Green LED
     */
    void BasicRGB::greenOff() { digitalWrite(GLED, OFF); };

    /*!
     * @brief Turns On Blue LED
     */
    void BasicRGB::blueOn() { digitalWrite(BLED, ON); };

    /*!
     * @brief Turns Off Blue LED
     */
    void BasicRGB::blueOff() { digitalWrite(BLED, OFF); };

    /*!
     * @brief Tests LED; visual purposes only.
     */
    void BasicRGB::basicColorTest()
    {
        redOn();
        delay(1000);
        redOff();
        delay(1000);
        greenOn();
        delay(1000);
        greenOff();
        delay(1000);
        blueOn();
        delay(1000);
        blueOff();
        delay(1000);
    }

} // namespace BasicRGB
