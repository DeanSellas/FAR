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
        mainLogger = mainLogger->GetInstance();
        mainLogger->Writeln("Adafruit MPU6050 test!");
        m_stateController = m_stateController->GetInstance();
        // Try to initialize!
        if (!this->Connect())
        {
            int i = 0;
            mainLogger->Writeln("Failed to find MPU6050 chip");
            mainLogger->Write("Trying Again...");
            while (i++ < 10 && !this->Connect())
            {
                delay(1000);
                mainLogger->Write('.');
            }
            if (!m_connected)
            {
                m_stateController->setFailure(MPU_NOT_FOUND);
                mainLogger->Writeln("No MPU6050 Found.");
                return;
            }
        }
        mainLogger->Writeln("MPU6050 Found!");

        m_adafruitMPU.setAccelerometerRange(MPU6050_RANGE_8_G);
        m_adafruitMPU.setGyroRange(MPU6050_RANGE_500_DEG);
        m_adafruitMPU.setFilterBandwidth(MPU6050_BAND_21_HZ);

#if DEBUG
        mainLogger->Write("Accelerometer range set to: ");
        switch (m_adafruitMPU.getAccelerometerRange())
        {
        case MPU6050_RANGE_2_G:
            mainLogger->Writeln("+-2G");
            break;
        case MPU6050_RANGE_4_G:
            mainLogger->Writeln("+-4G");
            break;
        case MPU6050_RANGE_8_G:
            mainLogger->Writeln("+-8G");
            break;
        case MPU6050_RANGE_16_G:
            mainLogger->Writeln("+-16G");
            break;
        }


        mainLogger->Write("Gyro range set to: ");
        switch (m_adafruitMPU.getGyroRange())
        {
        case MPU6050_RANGE_250_DEG:
            mainLogger->Writeln("+- 250 deg/s");
            break;
        case MPU6050_RANGE_500_DEG:
            mainLogger->Writeln("+- 500 deg/s");
            break;
        case MPU6050_RANGE_1000_DEG:
            mainLogger->Writeln("+- 1000 deg/s");
            break;
        case MPU6050_RANGE_2000_DEG:
            mainLogger->Writeln("+- 2000 deg/s");
            break;
        }
        mainLogger->Write("Filter bandwidth set to: ");
        switch (m_adafruitMPU.getFilterBandwidth())
        {
        case MPU6050_BAND_260_HZ:
            mainLogger->Writeln("260 Hz");
            break;
        case MPU6050_BAND_184_HZ:
            mainLogger->Writeln("184 Hz");
            break;
        case MPU6050_BAND_94_HZ:
            mainLogger->Writeln("94 Hz");
            break;
        case MPU6050_BAND_44_HZ:
            mainLogger->Writeln("44 Hz");
            break;
        case MPU6050_BAND_21_HZ:
            mainLogger->Writeln("21 Hz");
            break;
        case MPU6050_BAND_10_HZ:
            mainLogger->Writeln("10 Hz");
            break;
        case MPU6050_BAND_5_HZ:
            mainLogger->Writeln("5 Hz");
            break;
        }

        mainLogger->Writeln("");
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
        mainLogger->Write("Beginning MPU6050 Calibration\nPlease Do not move device durring this phase.");
        float accelerationValues[3] = {0.0f, 0.0f, 0.0f};
        float gyroValues[3] = {0.0f, 0.0f, 0.0f};
        for (int i = 0; i < samples; i++)
        {
            mainLogger->Write('.');
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
        mainLogger->Writeln("\nDone Calibrating!");
        mainLogger->Write("Offset Acceleration Values: ");
        mainLogger->Write(m_accelerationCalibration[0]);
        mainLogger->Write(", ");
        mainLogger->Write(m_accelerationCalibration[1]);
        mainLogger->Write(", ");
        mainLogger->Writeln(m_accelerationCalibration[2]);

        mainLogger->Write("Offset Gyro Values:");
        mainLogger->Write(m_gyroCalibration[0]);
        mainLogger->Write(", ");
        mainLogger->Write(m_gyroCalibration[1]);
        mainLogger->Write(", ");
        mainLogger->Writeln(m_gyroCalibration[2]);
#endif
    }

    void MPU6050::PrintValues()
    {

        /* Get new sensor events with the readings */
        sensors_event_t a, g, temp;
        m_adafruitMPU.getEvent(&a, &g, &temp);

        /* Print out the values */
        mainLogger->Write("Acceleration X: ");
        mainLogger->Write(a.acceleration.x);
        mainLogger->Write(", Y: ");
        mainLogger->Write(a.acceleration.y);
        mainLogger->Write(", Z: ");
        mainLogger->Write(a.acceleration.z);
        mainLogger->Writeln(" m/s^2");

        mainLogger->Write("Rotation X: ");
        mainLogger->Write(g.gyro.x);
        mainLogger->Write(", Y: ");
        mainLogger->Write(g.gyro.y);
        mainLogger->Write(", Z: ");
        mainLogger->Write(g.gyro.z);
        mainLogger->Writeln(" rad/s");

        mainLogger->Write("Temperature: ");
        mainLogger->Write(temp.temperature);
        mainLogger->Writeln(" degC");

        mainLogger->Writeln("");
    }
} // namespace Sensors::MPU6050
