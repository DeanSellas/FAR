/**
 * @file Logger.cpp
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright GNU General Public License v3.0
 *
 */

#include "Logger.h"

namespace Logger
{
    // initialize state controller to nullptr on launch
    Logger *Logger::m_instance = nullptr;
    const char *Logger::CurrentState()
    {
        switch (this->m_state)
        {
        case (0):
            return "TRACE";
        case (1):
            return "DEBUG";
        case (2):
            return "INFO";
        case (3):
            return "WARN";
        case (4):
            return "ERROR";
        case (5):
            return "CRITICAL";
        }
    }
} // namespace Logger
