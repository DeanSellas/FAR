/**
 * @file main.ino
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright GNU General Public License v3.0
 * 
 */

#include "src/pch.h"
#include "src/mpu6050test/adafruit_mpu6050.h"
#include "src/BasicRGB/BasicRGB.h"

BasicRGB::BasicRGB computerStatusLED_main = BasicRGB::BasicRGB(12, 11, 10);

void setup(void)
{
    computerStatusLED_main.ledSetup();

    Adafruit6050_setup();
    computerStatusLED_main.basicColorTest();
}

void loop(void)
{
    computerStatusLED_main.basicColorTest();
    //Adafruit6050_loop();
}