/**
 * @file StateController.cpp
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief State Controller
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright GNU General Public License v3.0
 *
 */

#include "../pch.h"

namespace FAR
{
    unsigned char StateController::getCurrentState() { return _currState; }
    unsigned char StateController::getFailureCode() { return _failureCode; }

    String StateController::getCurrentStateToString()
    {
        switch (_currState)
        {
        case BOOT:
            return "Boot";
        case ON_PAD_TESTS:
            return "Testing Sequence";
        case READY_FOR_LAUNCH:
            return "Ready For Launch";
        case FLIGHT:
            return "In Flight";
        case COAST:
            return "Coasting";
        case CHUTE_DEPLOYMENT:
            return "Deploying Parachutes";
        case DESCENT:
            return "Descending";
        case LANDING:
            return "Landing";
        case TOUCHDOWN:
            return "Touchdown";
        default:
            return "Unknown";
        }
    }
} // namespace FAR
