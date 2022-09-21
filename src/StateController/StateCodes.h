/**
 * @file StateCodes.h
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief States For the StateController
 * @version 0.1
 * @date 2022-09-20
 * 
 * @copyright GNU General Public License v3.0
 * 
 */

#pragma once

// States For Controller.
#define BOOT 0x00
#define ON_PAD_TESTS 0x01
#define READY_FOR_LAUNCH 0x03
#define FLIGHT 0x04
#define COAST 0x05
#define CHUTE_DEPLOYMENT 0x06
#define DESCENT 0x07
#define LANDING 0x08
#define TOUCHDOWN 0x09
#define FAILURE 0xFF