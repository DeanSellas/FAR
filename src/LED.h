/*!
 *  @file LED.h
 *
 * 	Basic LED Information and functions
 *
 *	GPL license (see license)
 */

#pragma once

#define RLED 12
#define GLED 11
#define BLED 10

// using a common cathode LED; LOW is ON; HIGH is OFF;
#define ON LOW
#define OFF HIGH
// Uncomment these lines if using common anode LED
// #define ON HIGH
// #define OFF LOW


void ledSetup();

/*!
 * @brief Turns off all LEDs
 */
void turnOffAll()
{
	digitalWrite(RLED, OFF);
	digitalWrite(GLED, OFF);
	digitalWrite(BLED, OFF);
}

/*!
 * @brief Turns On Red LED
 */
void redOn() { digitalWrite(RLED, ON); };

/*!
 * @brief Turns Off Red LED
 */
void redOff() { digitalWrite(RLED, OFF); };

/*!
 * @brief Turns On Green LED
 */
void greenOn() { digitalWrite(GLED, ON); };

/*!
 * @bgreenf Turns Off Green LED
 */
void greenOff() { digitalWrite(GLED, OFF); };

/*!
 * @brief Turns On Blue LED
 */
void blueOn() { digitalWrite(BLED, ON); };

/*!
 * @brief Turns Off Blue LED
 */
void blueOff() { digitalWrite(BLED, OFF); };

/*!
 * @brief Sets up LED pinmodes
 */
void ledSetup()
{
	turnOffAll();

	// Init LED
	pinMode(RLED, OUTPUT);
	pinMode(GLED, OUTPUT);
	pinMode(BLED, OUTPUT);
}

/*!
 * @brief Tests LED; visual purposes only.
 */
void basicColorTest()
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
}
