/**
 * @file main.ino
 * @author Dean Sellas (dean@deansellas.com)
 * @brief Main Execution Code for the flight controller. This will handle all the flight specific code and link together all the subsystems.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright GNU General Public License v3.0
 *
 */

#include "src/pch.h"
#include "src/Sensors/MPU6050/mpu6050.h"
#include "src/Sensors/BME280/bme280.h"


FAR::StateController::StateController *stateController;

Logger::Logger *mainLogger;
BasicLED::BasicRGB *computerStatusLED_main = new BasicLED::BasicRGB(12, 11, 10);

Sensors::MPU6050 *mainMPU;
Sensors::BME280 *mainBME;
bool endLoop = false, isLanded = false;
void setup(void)
{
    mainLogger = mainLogger->GetInstance(Logger::States::Debug);

    mainLogger->Writeln("FAR Initializing...");
    stateController = stateController->GetInstance();
    computerStatusLED_main->ledSetup();

    mainMPU = new Sensors::MPU6050();
    mainBME = new Sensors::BME280();

    if (stateController->getFailureCode() == FAILURE_NONE)
    {
        stateController->setState(ON_PAD_TESTS);
    }
}

void loop(void)
{
    if(isLanded)
    {
        landed();
        return;
    }

    // if error is thrown and logged, stop all code execution.
    switch (stateController->getCurrentState())
    {
    // if failure do nothing
    case (FAILURE):
        if (!endLoop)
        {
            mainLogger->Write("Failure Code: ", Logger::States::Error);
            mainLogger->Write(stateController->getCurrentFailureToString(), Logger::States::Error);
        }
        computerStatusLED_main->redOn();
        delay(1000);
        computerStatusLED_main->redOff();
        delay(1000);
        endLoop = true;
        return;
    case (ON_PAD_TESTS):
        computerStatusLED_main->blueOn();
        mainMPU->Calibrate();
        mainBME->Calibrate();
        computerStatusLED_main->blueOff();
        //stateController->setFailure(UNDEFINED_ERROR);
        mainLogger->Writeln("On Pad Tests Done... All Systems GO for launch!", Logger::States::Info);
        stateController->setState(READY_FOR_LAUNCH);
        return;
    case (ASCENT):
        computerStatusLED_main->turnOffAll();
        return;
    case (COAST):
        return;
    case (CHUTE_DEPLOYMENT):
        return;
    case (DESCENT):
        return;
    case (LANDING):
        return;
    case (TOUCHDOWN):
        // cleanup unneeded classes to save memory and battery life while waiting for recovery
        cleanup();
        landed();
    }
}

void cleanup()
{
    delete mainMPU;
    delete mainBME;
    mainMPU = NULL;
    mainBME = NULL;
    isLanded = true;
    return;
}

void landed()
{
    // TODO: IMPLEMENT
    computerStatusLED_main->greenOn();
    return;
}