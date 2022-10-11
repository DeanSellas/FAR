/**
 * @file BasicRGB.cpp
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief BasicRGB code. Custom Library to control RGB LEDs. Might release as a standalone library in the future.
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright GNU General Public License v3.0
 * 
 */
#include "../pch.h"
#include "BasicRGB.h"

namespace BasicRGB
{
    void BasicRGB::ledSetup()
    {
        turnOffAll();

        // Init LED
        pinMode(RLED, OUTPUT);
        pinMode(GLED, OUTPUT);
        pinMode(BLED, OUTPUT);
    }
    
    void BasicRGB::turnOffAll()
    {
        digitalWrite(RLED, offBit);
        digitalWrite(GLED, offBit);
        digitalWrite(BLED, offBit);
    }

    void BasicRGB::redOn() { digitalWrite(RLED, onBit); };

    void BasicRGB::redOff() { digitalWrite(RLED, offBit); };

    void BasicRGB::greenOn() { digitalWrite(GLED, onBit); };

    void BasicRGB::greenOff() { digitalWrite(GLED, offBit); };

    void BasicRGB::blueOn() { digitalWrite(BLED, onBit); };

    void BasicRGB::blueOff() { digitalWrite(BLED, offBit); };
 
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
