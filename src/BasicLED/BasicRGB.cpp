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

namespace BasicLED
{
    BasicRGB::BasicRGB(int r, int g, int b, LEDTypes type = LEDTypes::Cathode)
    {
        m_redLED = new BasicLED(r, type);
        m_blueLED = new BasicLED(b, type);
        m_greenLED = new BasicLED(g, type);
        
        switch (type)
        {
        case (LEDTypes::Cathode):
            onBit = LOW;
            offBit = HIGH;
            break;
        case (LEDTypes::Anode):
            onBit = HIGH;
            offBit = LOW;
            break;
        }
    }

    BasicRGB::~BasicRGB()
    {
        delete m_redLED;
        delete m_blueLED;
        delete m_greenLED;
    }

    void BasicRGB::ledSetup()
    {
        turnOffAll();
        mainLogger = mainLogger->GetInstance();
        // Init LED
        m_redLED->LEDSetup();
        m_greenLED->LEDSetup();
        m_blueLED->LEDSetup();
    }

    void BasicRGB::turnOffAll()
    {
        m_redLED->LEDOff();
        m_greenLED->LEDOff();
        m_blueLED->LEDOff();
    }

    void BasicRGB::redOn() { m_redLED->LEDOn(); };

    void BasicRGB::redOff() { m_redLED->LEDOff(); };

    void BasicRGB::greenOn() { m_greenLED->LEDOn(); };

    void BasicRGB::greenOff() { m_greenLED->LEDOff(); };

    void BasicRGB::blueOn() { m_blueLED->LEDOn(); };

    void BasicRGB::blueOff() { m_blueLED->LEDOff(); };

    void BasicRGB::basicColorTest(int t = 1000)
    {
        mainLogger->Writeln("Begin Color Test");
        redOn();
        delay(t);
        redOff();
        delay(t);
        greenOn();
        delay(t);
        greenOff();
        delay(t);
        blueOn();
        delay(t);
        blueOff();
        delay(t);
    }

}
