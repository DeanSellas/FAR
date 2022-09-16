#include <Arduino.h>

#include "src/mpu6050test/adafruit_mpu6050.h"
#include "src/LED.h"

void setup(void)
{
	ledSetup();

	Adafruit6050_setup();
	basicColorTest();
}

void loop(void)
{
	Adafruit6050_loop();
}