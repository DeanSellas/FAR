# F.A.R :rocket:
F.A.R is my first iteration of a on board rocket flight computer. F.A.R stands for Flight Avionics Recorder. This iteration of my flight computer will focus on logging data and fine tuning senor calibration. There will be basic flight control logic to control parachute deployment, but I will not be including TVC or any communication with a ground station. These things will come in a future project after I get the basics down.

## Goals
* Accelerometer
  * Get Basic Readings
  * Self Calibration
  * Location Guessing
* Barometer
  * ????
* Log data to SD Card
  * ????
* Self Tests
  * Ground Sensor Testing
  * Launch Pad Tests
* Stage Detection
  * Waiting On Pad
  * Takeoff
  * Apoapsis
  * Chute Deployment
  * Decent
  * Landing


### Parts List
* [Arduino Uno](https://store-usa.arduino.cc/products/arduino-uno-rev3)
  * will most likely replace with smaller board later.
* [MPU6050](https://www.amazon.com/HiLetgo-MPU-6050-Accelerometer-Gyroscope-Converter/dp/B078SS8NQV) Accelerometer
* [BME280](https://www.adafruit.com/product/2652)
  * subject to change
* [MicroSD](https://www.adafruit.com/product/4682)
  * subject to change
* [SPI Chip](https://www.sparkfun.com/products/15809)
  * [Alternate](https://www.adafruit.com/product/4899) 


### Important Links
* [MPU6050 Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/)
* [MPU6050 library](https://github.com/jrowberg/i2cdevlib)
* [Adafruit MPU6050 Library](https://github.com/adafruit/Adafruit_MPU6050)