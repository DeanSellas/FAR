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
        m_stateController = m_stateController->GetInstance();
        // Try to initialize!
        if (!this->Connect())
        {
            int i = 0;
            Serial.println("Failed to find MPU6050 chip");
            Serial.print("Trying Again...");
            while (i++ < 10 && !this->Connect())
            {
                delay(1000);
                Serial.print('.');
            }
            if (!m_connected)
            {
                m_stateController->setFailure(MPU_NOT_FOUND);
                Serial.println("No MPU6050 Found.");
                return;
            }
        }
        Serial.println("MPU6050 Found!");

        m_adafruitMPU.setAccelerometerRange(MPU6050_RANGE_8_G);
        m_adafruitMPU.setGyroRange(MPU6050_RANGE_500_DEG);
        m_adafruitMPU.setFilterBandwidth(MPU6050_BAND_21_HZ);

#if DEBUG
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
#endif

        delay(100);
    }

    bool MPU6050::Connect()
    {
        m_connected = m_adafruitMPU.begin();
        return m_connected;
    }

    void MPU6050::Calibrate(int samples = 100)
    {
        Serial.print("Beginning MPU6050 Calibration\nPlease Do not move device durring this phase.");
        float accelerationValues[3] = {0.0f, 0.0f, 0.0f};
        float gyroValues[3] = {0.0f, 0.0f, 0.0f};
        for (int i = 0; i < samples; i++)
        {
            Serial.print('.');
            sensors_event_t a, g, t;
            m_adafruitMPU.getEvent(&a, &g, &t);
            accelerationValues[0] += a.acceleration.x;
            accelerationValues[1] += a.acceleration.y;
            accelerationValues[2] += a.acceleration.z;

            gyroValues[0] += g.gyro.x;
            gyroValues[1] += g.gyro.y;
            gyroValues[2] += g.gyro.z;
            delay(100);
        }
        m_accelerationCalibration[0] = accelerationValues[0] / samples;
        m_accelerationCalibration[2] = accelerationValues[2] / samples;
        m_accelerationCalibration[3] = accelerationValues[3] / samples;

        m_gyroCalibration[0] = gyroValues[0] / samples;
        m_gyroCalibration[1] = gyroValues[1] / samples;
        m_gyroCalibration[2] = gyroValues[2] / samples;
#if DEBUG
        Serial.println("\nDone Calibrating!");
        Serial.print("Offset Acceleration Values: ");
        Serial.print(m_accelerationCalibration[0]);
        Serial.print(", ");
        Serial.print(m_accelerationCalibration[1]);
        Serial.print(", ");
        Serial.println(m_accelerationCalibration[2]);

        Serial.print("Offset Gyro Values:");
        Serial.print(m_gyroCalibration[0]);
        Serial.print(", ");
        Serial.print(m_gyroCalibration[1]);
        Serial.print(", ");
        Serial.println(m_gyroCalibration[2]);
#endif
    }

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
