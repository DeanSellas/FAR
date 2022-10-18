/**
 * @file MPU6050.h
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright GNU General Public License v3.0
 * 
 */


#pragma once
#include <Adafruit_MPU6050.h>
namespace Sensors
{
    class MPU6050
    {
    private:
        Adafruit_MPU6050 m_adafruitMPU;

    public:
        MPU6050();
        ~MPU6050();

        void PrintValues();
    };

} // namespace MPU6050