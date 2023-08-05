/**
 * @file MPU6050.h
 * @author Dean Sellas (dean@deansellas.com)
 * @brief
 * @version 0.1
 * @date 2022-10-17
 *
 * @copyright GNU General Public License v3.0
 *
 */

#pragma once
#include <Adafruit_MPU6050.h>
#include "../sensor.h"

namespace Sensors
{
    class MPU6050 : public Sensor
    {
    private:
        Adafruit_MPU6050 m_adafruitMPU;
        float m_accelerationCalibration[3] = {0.0f, 0.0f, 0.0f}; // [x,y,z]
        float m_gyroCalibration[3] = {0.0f, 0.0f, 0.0f};         // [x,y,z]

    public:
        /**
         * @brief Construct a new MPU6050 object
         *
         */
        MPU6050();

        /**
         * @brief Destroy the MPU6050 object
         *
         */
        ~MPU6050(){};

        /**
         * @brief Tries to connect to the MPU6050
         *
         * @return true
         * @return false
         */
        bool Connect();

        void Calibrate(int samples = 100);

        void PrintValues();
    };

} // namespace MPU6050