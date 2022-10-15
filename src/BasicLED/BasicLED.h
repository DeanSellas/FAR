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
        char m_OnBit, m_OffBit;
        int m_LEDPin;

    public:
        /**
         * @brief Construct a new BasicLED object. Assumes Common Cathode LEDs
         *
         * @param pin Pin LED is Connected to.
         */
        BasicLED(int pin, LEDTypes type = LEDTypes::Cathode);

        /**
         * @brief Construct a new BasicLED object. User defined On and Off Bit
         *
         * @param pin Pin LED is Connected to.
         * @param on_bit On Bit (HIGH or LOW), used to turn LEDs on.
         * @param off_bit Off Bit (HIGH or LOW), used to turn LEDs off.
         */
        // BasicLED(int pin, char on_bit, char off_bit) : m_LEDPin(pin), m_OnBit(on_bit), m_OffBit(off_bit){};

        ~BasicLED(){};

        /**
         * @brief Turns LED On
         */
        void LEDOn();

        /**
         * @brief Turns LED Off
         */
        void LEDOff();
    };

} // namespace BasicLED
