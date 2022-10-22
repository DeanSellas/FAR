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
#include "src/Sensors/MPU6050/mpu6050.h"
#include "src/BasicLED/BasicRGB.h"
#include "src/BasicLED/BasicLED.h"

FAR::StateController::StateController* stateController;

BasicLED::BasicRGB computerStatusLED_main(12, 11, 10);
Sensors::MPU6050* mainMPU;
bool endLoop = false;
void setup(void)
{
    Serial.begin(115200);
    Serial.println("FAR Initilizing...");
    stateController = stateController->GetInstance();
    computerStatusLED_main.ledSetup();

    mainMPU = new Sensors::MPU6050();

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