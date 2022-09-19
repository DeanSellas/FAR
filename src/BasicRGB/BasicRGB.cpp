/**
 * @file BasicRGB.cpp
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief BasicRGB code. Custom Library to control RGB LEDs. Might release as a standalone library in the future.
 * @version 1.0
 * @date 2022-09-18
 * 
 * @copyright GNU General Public License v3.0
 * 
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
        digitalWrite(RLED, LED_OFF);
        digitalWrite(GLED, LED_OFF);
        digitalWrite(BLED, LED_OFF);
    }

    /*!
     * @brief Turns On Red LED
     */
    void BasicRGB::redOn() { digitalWrite(RLED, LED_ON); };

    /*!
     * @brief Turns Off Red LED
     */
    void BasicRGB::redOff() { digitalWrite(RLED, LED_OFF); };

    /*!
     * @brief Turns On Green LED
     */
    void BasicRGB::greenOn() { digitalWrite(GLED, LED_ON); };

    /*!
     * @bgreenf Turns Off Green LED
     */
    void BasicRGB::greenOff() { digitalWrite(GLED, LED_OFF); };

    /*!
     * @brief Turns On Blue LED
     */
    void BasicRGB::blueOn() { digitalWrite(BLED, LED_ON); };

    /*!
     * @brief Turns Off Blue LED
     */
    void BasicRGB::blueOff() { digitalWrite(BLED, LED_OFF); };

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

}
