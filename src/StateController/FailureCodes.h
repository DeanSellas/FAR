/**
 * @file FailureCodes.h
 * @author Dean Sellas (dean@deansellas.com)
 * @brief Failure Codes For State Controller
 * @version 0.1
 * @date 2022-09-20
 * 
 * @copyright GNU General Public License v3.0
 * 
 */
#pragma once

#include "../pch.h"

#define FAILURE_NONE 0x00       // No Failure
#define UNDEFINED_ERROR 0xFF    // Unknown Failure... Please create a report so it can be debugged and added to the software
#define MPU_NOT_FOUND 0x01      // MPU6050 not detected. CRITICAL ERROR - Rocket will not launch.
#define BME_NOT_FOUND 0x02      // BME280 not detected. CRITICAL ERROR - Rocket will not launch.