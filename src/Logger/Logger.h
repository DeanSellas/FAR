/**
 * @file Logger.h
 * @author Dean Sellas (dgsellas@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-11
 *
 * @copyright GNU General Public License v3.0
 *
 */

#pragma once
#include "../pch.h"
#include "LoggerStates.h"

namespace Logger
{
    class Logger
    {
    private:
        int m_state;
        static Logger *m_instance;
        Logger(int _state) : m_state(_state){};

    public:
        static Logger *GetInstance()
        {
            if (!m_instance)
            {
                m_instance = new Logger(DEBUG);
            }
            return m_instance;
        };
        static Logger *GetInstance(int _state)
        {
            if (!m_instance)
            {
                m_instance = new Logger(DEBUG);
            }
            return m_instance;
        };
        ~Logger(){};

        template <typename T = const char *>
        void Logger::Write(T message)
        {
            Serial.print(message);
        }
        template <typename T = const char *>
        void Logger::Write(int state, T message)
        {
            if (this->m_state <= state)
            {
                Serial.print(message);
            }
        }
        template <typename T = const char *>
        void Logger::Writeln(T message)
        {
            Serial.println(message);
        }
        template <typename T = const char *>
        void Logger::Writeln(int state, T message)
        {
            if (this->m_state <= state)
            {
                Serial.println(message);
            }
        }
        const char *CurrentState();
    };
} // namespace Logger
