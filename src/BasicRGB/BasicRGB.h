/*!
 *  @file LED.h
 *
 * 	Basic LED Information and functions
 *
 *	GPL license (see license)
 */

#pragma once

// using a common cathode LED; LOW is ON; HIGH is OFF;
#define ON LOW
#define OFF HIGH
// Uncomment these lines if using common anode LED
// #define ON HIGH
// #define OFF LOW


namespace BasicRGB {
    class BasicRGB
    {
    private:
        int RLED;
        int GLED;
        int BLED;

    public:
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

