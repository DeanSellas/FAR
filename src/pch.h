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

#include <Arduino.h>

// using a common cathode LED; LOW is ON; HIGH is OFF;
#define LED_ON LOW
#define LED_OFF HIGH
// Uncomment these lines if using common anode LED
// #define ON HIGH
// #define OFF LOW