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

FAR::StateController::StateController computerStateController_main;

BasicLED::BasicRGB computerStatusLED_main(12, 11, 10);
Sensors::MPU6050* mainMPU;
bool endLoop = false;
void setup(void)
{
    Serial.begin(115200);
    Serial.println("FAR Initilizing...");
    computerStatusLED_main.ledSetup();

    mainMPU = new Sensors::MPU6050();

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
    // if error is thrown and logged, stop all code execution.
    if(endLoop)
        return;

    switch (computerStateController_main.getCurrentState())
    {
    // if failure do nothing
    case (FAILURE):
        Serial.print("Failure Code: ");
        Serial.println(computerStateController_main.getCurrentFailureToString());
        endLoop = true;
        return;
    case (ON_PAD_TESTS):
        computerStatusLED_main.basicColorTest();
        computerStateController_main.setFailure(UNDEFINED_ERROR);
        return;
    }
}