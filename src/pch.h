/**
 * @file pch.h
 * @author Dean Sellas (you@domain.com)
 * @brief Precompiled Headers File. Put Header Files and Defines that will be shared across entire program.
 * @version 1.0
 * @date 2022-09-18
 *
 * @copyright GNU General Public License v3.0
 *
 */

#pragma once


// Arduino Includes
#include <Arduino.h>

// State Controller Includes
#include "StateController/StateCodes.h"
#include "StateController/FailureCodes.h"
#include "StateController/StateController.h"

// Logger Includes
#include "Logger/Logger.h"
#include "Logger/LoggerStates.h"

// BasicLED Includes
#include "vendor/BasicLED/src/LEDTypes.h"
#include "vendor/BasicLED/src/BasicLED.h"
#include "vendor/BasicLED/src/BasicRGB.h"

// Debug Value used to disable Serial Logging (saves a lot of memory)
#define DEBUG 0

// using a common cathode LED; LOW is ON; HIGH is OFF;
#define LED_ON LOW
#define LED_OFF HIGH
// Uncomment these lines if using common anode LED
// #define ON HIGH
// #define OFF LOW