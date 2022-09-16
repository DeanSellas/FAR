#include <Arduino.h>

#include "src/mpu6050test/adafruit_mpu6050.h"

void setup(void) {
    Adafruit6050_setup();
}

void loop(void) {
    Adafruit6050_loop();
}