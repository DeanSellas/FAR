/**
 * @file sensor.h
 * @author Dean Sellas (dean@deansellas.com)
 * @brief Sensor Parent Class
 * @version 0.1
 * @date 2023-08-05
 * 
 * @copyright GNU General Public License v3.0
 * 
 */
#pragma once
#include "../StateController/StateController.h"


namespace Sensors
{
    class Sensor
    {
    protected:
        bool m_connected = false;
        FAR::StateController::StateController *m_stateController;
        Logger::Logger *mainLogger;

    public:
        Sensor()
        {
            mainLogger = mainLogger->GetInstance();
            m_stateController = m_stateController->GetInstance();
        };
        ~Sensor()
        {
            delete m_stateController;
            delete mainLogger;

            m_stateController = NULL;
            mainLogger = NULL;
        };

        /**
         * @brief Tries to connect to the BME280
         * 
         * @return true/false
         */
        virtual bool Connect() = 0;

        /**
         * @brief Calibrates the BME280
         * 
         */
        virtual void Calibrate(unsigned int samples = 100) = 0;

    };
    
} // namespace Sensors
