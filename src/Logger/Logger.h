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
        bool m_serial;
        static Logger *m_instance;
        Logger(int _state, bool _serial = true) : m_state(_state), m_serial(_serial)
        {
            if (m_serial)
            {
                Serial.begin(115200);
            }
        };

    public:
        
        static Logger *GetInstance()
        {
            return GetInstance(States::Trace, true);
        };

        static Logger *GetInstance(bool _serial)
        {
            return GetInstance(States::Debug, _serial);
        };

        static Logger *GetInstance(int _state)
        {
            return GetInstance(_state, true);
        };
        static Logger *GetInstance(int _state, bool _serial)
        {
            if (!m_instance)
            {
                m_instance = new Logger(_state);
            }
            return m_instance;
        };

        ~Logger(){};

        template <typename T = const char *>
        void Logger::Write(T message)
        {
            if (m_serial)
            {
                Serial.print(message);
            }
        }
        template <typename T = const char *>
        void Logger::Write(int state, T message)
        {
            if (this->m_state <= state && m_serial)
            {
                Serial.print(message);
            }
        }
        template <typename T = const char *>
        void Logger::Writeln(T message)
        {
            if (m_serial)
            {
                Serial.println(message);
            }
        }
        template <typename T = const char *>
        void Logger::Writeln(int state, T message)
        {
            if (this->m_state <= state && m_serial)
            {
                Serial.println(message);
            }
        }
        const char *CurrentState();
    };
} // namespace Logger
