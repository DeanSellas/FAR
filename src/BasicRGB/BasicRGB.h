/**
 * @file BasicRGB.h
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief BasicRGB Definitions
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright GNU General Public License v3.0
 *
 */

#pragma once

namespace BasicRGB
{
    class BasicRGB
    {
    private:
        int RLED;
        int GLED;
        int BLED;
        char onBit, offBit;

    public:
        /**
         * @brief Construct a new BasicRGB object. Will assume common Cathode LED
         *
         * @param r Red LED Pin
         * @param g Green LED Pin
         * @param b Blue LED Pin
         */
        BasicRGB(int r, int g, int b) : RLED(r), GLED(g), BLED(b)
        {
            onBit = LOW;
            offBit = HIGH;
        };

        /**
         * @brief Construct a new BasicRGB object. Custom on and off bit preference.
         *
         * @param r Red LED Pin
         * @param g Green LED Pin
         * @param b Blue LED Pin
         * @param on On Bit (HIGH or LOW), used to turn on LEDs
         * @param off Off Bit (HIGH or LOW), used to turn off LEDs
         */
        BasicRGB(int r, int g, int b, char on, char off) : RLED(r), GLED(g), BLED(b), onBit(on), offBit(off){};

        /**
         * @brief Destroy the BasicRGB object.
         */
        ~BasicRGB(){};

        /*!
         * @brief Sets up LED pinmodes
         */
        void ledSetup();

        /*!
         * @brief Turns off all LEDs
         */
        void turnOffAll();

        /*!
         * @brief Turns On Red LED
         */
        void redOn();

        /*!
         * @brief Turns Off Red LED
         */
        void redOff();

        /*!
         * @brief Turns On Green LED
         */
        void greenOn();

        /*!
         * @bgreenf Turns Off Green LED
         */
        void greenOff();

        /*!
         * @brief Turns On Blue LED
         */
        void blueOn();

        /*!
         * @brief Turns Off Blue LED
         */
        void blueOff();

        /*!
         * @brief Tests LED; visual purposes only.
         */
        void basicColorTest();
    };
}