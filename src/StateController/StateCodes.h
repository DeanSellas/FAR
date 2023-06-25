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
#define FAILURE 0xFF            // System has encountered failure. See FailureCodes.h
#define BOOT 0x00               // Default Startup State. Basic Configuration and Tests
#define ON_PAD_TESTS 0x01       // System getting ready and configuring subsystems
#define READY_FOR_LAUNCH 0x03   // System reporting GO for Launch, waiting for user to begin Ascent
#define ASCENT 0x04             // Boosters burning and Rocket is Accelerating
#define COAST 0x05              // Acceleration slowing down, getting read to deploy chutes at AP
#define CHUTE_DEPLOYMENT 0x06   // AP hit or descent has begun, chutes deploying
#define DESCENT 0x07            // Rocket is returning to ground
#define LANDING 0x08            // Within 20m of ground
#define TOUCHDOWN 0x09          // Acceleration has stopped. Rocket is touched down