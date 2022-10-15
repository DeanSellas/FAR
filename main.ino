/**
 * @file main.ino
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright GNU General Public License v3.0
 *
 */

#include "src/pch.h"
#include "src/mpu6050test/adafruit_mpu6050.h"
#include "src/BasicLED/BasicRGB.h"
#include "src/BasicLED/BasicLED.h"

FAR::StateController::StateController computerStateController_main;

BasicLED::BasicRGB computerStatusLED_main(12, 11, 10);

void setup(void)
{
    computerStatusLED_main.ledSetup();

    Adafruit6050_setup();
    computerStatusLED_main.basicColorTest();

    if (computerStateController_main.getFailureCode() == FAILURE_NONE)
    {
        computerStateController_main.setState(ON_PAD_TESTS);
    }
    else
    {
        computerStateController_main.setState(FAILURE);
    }
}

void loop(void)
{
    switch (computerStateController_main.getCurrentState())
    {
    // if failure do nothing
    case (FAILURE):
        Serial.println(computerStateController_main.getFailureCode());
        return;
    case (BOOT):
        computerStateController_main.setFailure(UNDEFINED_ERROR);
        return;
    }
}