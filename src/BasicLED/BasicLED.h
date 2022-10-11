/**
 * @file BasicLED.h
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief BasicLED Definitions
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright GNU General Public License v3.0
 *
 */
#pragma once

namespace BasicLED
{
    class BasicLED
    {
    private:
        char onBit, offBit;

    public:
        /**
         * @brief Construct a new BasicLED object. Assumes Common Cathode LEDs
         */
        BasicLED()
        {
            onBit = LOW;
            offBit = HIGH;
        };

        /**
         * @brief Construct a new BasicLED object. User defined On and Off Bit
         * 
         * @param on_bit On Bit (HIGH or LOW), used to turn LEDs on.
         * @param off_bit Off Bit (HIGH or LOW), used to turn LEDs off.
         */
        BasicLED(char on_bit, char off_bit) : onBit(on_bit), offBit(off_bit) {};

        ~BasicLED(){};
    };

} // namespace BasicLED
