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
#include "src/BasicRGB/BasicRGB.h"

FAR::StateController::StateController* stateController;

BasicRGB::BasicRGB computerStatusLED_main(12, 11, 10);
bool endLoop = false;
void setup(void)
{
    Serial.begin(115200);
    stateController = stateController->GetInstance();
    computerStatusLED_main.ledSetup();

    Adafruit6050_setup();

    if (stateController->getFailureCode() == FAILURE_NONE)
    {
        stateController->setState(ON_PAD_TESTS);
    }
    else
    {
        stateController->setState(FAILURE);
    }
}

void loop(void)
{
    // if error is thrown and logged, stop all code execution.
    if(endLoop)
        return;

    switch (stateController->getCurrentState())
    {
    // if failure do nothing
    case (FAILURE):
        Serial.print("Failure Code: ");
        Serial.println(stateController->getCurrentFailureToString());

        endLoop = true;
        return;
    case (ON_PAD_TESTS):
        computerStatusLED_main.basicColorTest();
        Serial.println(stateController->getCurrentStateToString());
        stateController->setFailure(UNDEFINED_ERROR);

        return;
    }
}