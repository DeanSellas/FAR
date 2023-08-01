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
        float surface_pressure;

        Adafruit_BME280 m_adafruitBME;
        bool m_connected = false;
        
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
        ~BME280() {};

        /**
         * @brief Tries to connect to the BME280
         * 
         * @return true/false
         */
        bool Connect();

        /**
         * @brief Calibrates the BME280
         * 
         */
        void Calibrate();

        /**
         * @brief Sets the Surface Pressure
         * 
         * @param samples how many times to sample pressure; more samples the more accurate.
         * @return float 
         */
        float SetSurfacePressure(int samples = 1);

        /**
         * @brief Get the Surface Pressure
         * 
         * @return float 
         */
        float GetSurfacePressure();

        /**
         * @brief Get the Pressure
         * 
         * @return float 
         */
        float GetPressure();

        /**
         * @brief Get the Temperature
         * 
         * @return float 
         */
        float GetTemperature();

        /**
         * @brief Get the Altitude
         * 
         * @return float 
         */
        float GetAltitude(bool sealevel = true);

        /**
         * @brief Prints BME280 values
         * 
         */
        void PrintValues();
    };
    
} // namespace Sensors
