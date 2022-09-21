/**
 * @file StateController.h
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief State Controller Definitions
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright GNU General Public License v3.0
 *
 */

#pragma once
#include "../pch.h"

namespace FAR
{
    /**
     * @brief State Controller Object
     *
     */
    class StateController
    {
    private:
        unsigned char _currState;
        unsigned char _failureCode;

    public:
        /**
         * @brief Construct a new State Controller object
         *
         */
        StateController() : _currState(BOOT), _failureCode(FAILURE_NONE) {};

        /**
         * @brief Construct a new State Controller object
         * 
         * @param startingState Starting State for the Computer.
         * @param startingFailure (optional) Starting Failure Code for the Computer
         */
        StateController(unsigned char startingState, unsigned char startingFailure = FAILURE_NONE) : _currState(startingState), _failureCode(startingFailure){};
        ~StateController();

        /**
         * @brief Get the Current State of the Computer
         * 
         * @return State Code (unsigned char)
         */
        unsigned char getCurrentState();

        /**
         * @brief Get the Failure Code the Computer is Reporting
         * 
         * @return Failure Code (unsigned char) 
         */
        unsigned char getFailureCode();

        String getCurrentStateToString();
    };
} // namespace FAR