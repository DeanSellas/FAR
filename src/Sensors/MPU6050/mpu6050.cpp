/**
 * @file mpu6050.cpp
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief mpu6050 code, currently based on adafruits demo. will change it in the future.
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright GNU General Public License v3.0
 * 
 */

#include "mpu6050.h"
#include <Adafruit_Sensor.h>


namespace Sensors
{
    MPU6050::MPU6050()
    {
        Serial.println("Adafruit MPU6050 test!");

        // Try to initialize!
        if (!m_adafruitMPU.begin())
        {
            Serial.println("Failed to find MPU6050 chip");
            while (1)
            {
                delay(10);
            }
        }
        Serial.println("MPU6050 Found!");

        m_adafruitMPU.setAccelerometerRange(MPU6050_RANGE_8_G);
        Serial.print("Accelerometer range set to: ");
        switch (m_adafruitMPU.getAccelerometerRange())
        {
        case MPU6050_RANGE_2_G:
            Serial.println("+-2G");
            break;
        case MPU6050_RANGE_4_G:
            Serial.println("+-4G");
            break;
        case MPU6050_RANGE_8_G:
            Serial.println("+-8G");
            break;
        case MPU6050_RANGE_16_G:
            Serial.println("+-16G");
            break;
        }
        m_adafruitMPU.setGyroRange(MPU6050_RANGE_500_DEG);
        Serial.print("Gyro range set to: ");
        switch (m_adafruitMPU.getGyroRange())
        {
        case MPU6050_RANGE_250_DEG:
            Serial.println("+- 250 deg/s");
            break;
        case MPU6050_RANGE_500_DEG:
            Serial.println("+- 500 deg/s");
            break;
        case MPU6050_RANGE_1000_DEG:
            Serial.println("+- 1000 deg/s");
            break;
        case MPU6050_RANGE_2000_DEG:
            Serial.println("+- 2000 deg/s");
            break;
        }

        m_adafruitMPU.setFilterBandwidth(MPU6050_BAND_21_HZ);
        Serial.print("Filter bandwidth set to: ");
        switch (m_adafruitMPU.getFilterBandwidth())
        {
        case MPU6050_BAND_260_HZ:
            Serial.println("260 Hz");
            break;
        case MPU6050_BAND_184_HZ:
            Serial.println("184 Hz");
            break;
        case MPU6050_BAND_94_HZ:
            Serial.println("94 Hz");
            break;
        case MPU6050_BAND_44_HZ:
            Serial.println("44 Hz");
            break;
        case MPU6050_BAND_21_HZ:
            Serial.println("21 Hz");
            break;
        case MPU6050_BAND_10_HZ:
            Serial.println("10 Hz");
            break;
        case MPU6050_BAND_5_HZ:
            Serial.println("5 Hz");
            break;
        }

        Serial.println("");
        delay(100);
    }
    MPU6050::~MPU6050() {}

    void MPU6050::PrintValues()
    {

        /* Get new sensor events with the readings */
        sensors_event_t a, g, temp;
        m_adafruitMPU.getEvent(&a, &g, &temp);

        /* Print out the values */
        Serial.print("Acceleration X: ");
        Serial.print(a.acceleration.x);
        Serial.print(", Y: ");
        Serial.print(a.acceleration.y);
        Serial.print(", Z: ");
        Serial.print(a.acceleration.z);
        Serial.println(" m/s^2");

        Serial.print("Rotation X: ");
        Serial.print(g.gyro.x);
        Serial.print(", Y: ");
        Serial.print(g.gyro.y);
        Serial.print(", Z: ");
        Serial.print(g.gyro.z);
        Serial.println(" rad/s");

        Serial.print("Temperature: ");
        Serial.print(temp.temperature);
        Serial.println(" degC");

        Serial.println("");
    }
} // namespace Sensors::MPU6050


