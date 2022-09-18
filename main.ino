#include "src/pch.h"
#include "src/mpu6050test/adafruit_mpu6050.h"
#include "src/BasicRGB/BasicRGB.h"

BasicRGB::BasicRGB a = BasicRGB::BasicRGB(12, 11, 10);

void setup(void)
{
    a.ledSetup();

    Adafruit6050_setup();
    a.basicColorTest();
}

void loop(void)
{
    //basicColorTest();
    //Adafruit6050_loop();
}