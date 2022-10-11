/**
 * @file BasicLED.cpp
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright GNU General Public License v3.0
 *
 */

#include "../pch.h"
#include "BasicLED.h"

namespace BasicLED
{
    void BasicLED::LEDOn()
    {
        digitalWrite(m_LEDPin, m_OnBit);
    }
    void BasicLED::LEDOff()
    {
        digitalWrite(m_LEDPin, m_OffBit);
    }
} // namespace BasicLED
