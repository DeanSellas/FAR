/**
 * @file bme280.cpp
 * @author Dean Sellas (dean@deansellas.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-27
 * 
 * @copyright GNU General Public License v3.0
 * 
 */

#include "bme280.h"

namespace Sensors
{
    BME280::BME280()
    {
        mainLogger->Writeln("Adafruit BME280 Test");

        // try to initialize
        if(!this->Connect())
        {
            byte i = 0;
            mainLogger->Writeln("Failed to find BME280 chip");
            //mainLogger->Write("Trying Again...");
            while (i++ < 10 && !this->Connect())
            {
                delay(1000);
                //mainLogger->Write('.');
            }
            if (!m_connected)
            {
                m_stateController->setFailure(BME_NOT_FOUND);
                mainLogger->Writeln("No BME280 Found.", Logger::States::Error);
                return;
            }
        }
        mainLogger->Writeln("BME280 Found!");
    }

    bool BME280::Connect()
    {
        m_connected = m_adafruitBME.begin();
        return m_connected;
    }

    void BME280::Calibrate(unsigned int samples = 100)
    {
        mainLogger->Writeln("Beginning BME280 Calibration\nPlease Do not move device durring this phase.");
        this->surface_pressure = SetSurfacePressure(samples);
        mainLogger->Writeln("Done Calibrating BME280");
    }

    float BME280::SetSurfacePressure(unsigned int samples = 1)
    {
        float average = 0.0f;

        for(int i = 0; i < samples; i++)
        {
            average += m_adafruitBME.readPressure();
        }
        return average / samples;
    }

    float BME280::GetSurfacePressure()
    {
        return this->surface_pressure;
    }

    float BME280::GetPressure()
    {
        return m_adafruitBME.readPressure();
    }

    float BME280::GetTemperature()
    {
        return m_adafruitBME.readTemperature();
    }

    float BME280::GetAltitude(bool sealevel = true)
    {
        if(sealevel)
            return m_adafruitBME.readAltitude(sea_level_pressure);
        else
            return m_adafruitBME.readAltitude(surface_pressure);
    }

    void PrintValues()
    {
        //todo: implement print function
        return;
    }
} // namespace Sensors
