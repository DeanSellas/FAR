/**
 * @file bme280.h
 * @author Dean Sellas (dean@deansellas.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-27
 * 
 * @copyright GNU General Public License v3.0
 * 
 */

#pragma once
#include <Adafruit_BME280.h>
#include "../../StateController/StateController.h"
namespace Sensors
{
    class BME280
    {
    private:
        // generic sea level pressure.
        const float sea_level_pressure = 1013.25f;

        Adafruit_BME280 m_adafruitBME;
        bool m_connected = false;
        
        float m_pressure;
        float m_tempurature;
        float m_humidity;
        float m_altitude;

        FAR::StateController::StateController *m_stateController;
        Logger::Logger *mainLogger;


    public:
        /**
        * @brief Construct a new BME280 object
        * 
        */
        BME280();
        
        
        /**
        * @brief Destroy the BME280 object
        * 
        */
        ~BME280();
    };
    
} // namespace Sensors
