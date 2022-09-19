/**
 * @file BasicRGB.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright GNU General Public License v3.0
 * 
 */

#pragma once




namespace BasicRGB {
    class BasicRGB
    {
    private:
        int RLED;
        int GLED;
        int BLED;

    public:
        /**
         * @brief Construct a new Basic RGB object
         * 
         * @param r Red LED Pin
         * @param g Green LED Pin
         * @param b Blue LED Pin
         */
        BasicRGB(int r, int g, int b) : RLED(r), GLED(g), BLED(b) {};
        ~BasicRGB() {};
        void ledSetup();
        void turnOffAll();
        void redOn();
        void redOff();
        void greenOn();
        void greenOff();
        void blueOn();
        void blueOff();

        void basicColorTest();
    };
}

