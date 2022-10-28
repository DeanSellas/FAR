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

namespace FAR::StateController
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
        static StateController *m_instance;
        /**
         * @brief Construct a new State Controller object
         *
         */
        StateController()
        {
            _currState = BOOT;
            _failureCode = FAILURE_NONE;
        };

    public:
        /**
         * @brief Get the Instance of Singleton
         *
         * @return StateController*
         */
        static StateController *GetInstance()
        {
            if (!m_instance)
            {
                m_instance = new StateController();
            }
            return m_instance;
        }

        ~StateController(){};

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

        /**
         * @brief Set the State of the controller
         *
         * @param state
         */
        void setState(unsigned char state);

        /**
         * @brief Set the Failure Code of the Controller
         *
         * @param failure
         */
        void setFailure(unsigned char failure);

        /**
         * @brief Returns True or False based on if there is a Failure Code stored in the StateController
         *
         * @return true
         * @return false
         */
        bool isFailure();

        /**
         * @brief Returns the Current State as a String
         *
         * @return String
         */
        String getCurrentStateToString();

        /**
         * @brief Returns the Current Failure as a String
         *
         * @return String
         */
        String getCurrentFailureToString();
    };
} // namespace FAR