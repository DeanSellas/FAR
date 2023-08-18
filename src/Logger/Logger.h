/**
 * @file Logger.h
 * @author Dean Sellas (dean@deansellas.com)
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
        byte m_state;
        bool m_serial;
        static Logger *m_instance;
        
        Logger(byte _state, bool _serial = true) : m_state(_state), m_serial(_serial)
        {
            if (m_serial)
            {
                Serial.begin(115200);
            }
        };

    public:
        
        static Logger *GetInstance(byte _state = States::Debug, bool _serial = true)
        {
            if (!m_instance)
            {
                m_instance = new Logger(_state, _serial);
            }
            return m_instance;
        };

        ~Logger()
        {
            delete m_instance;
            m_instance = nullptr;
        };

        template <typename T = const char *>
        void Logger::Write(T message, byte state = States::Debug)
        {
            if (this->m_state <= state && m_serial)
            {
                Serial.print(message);
            }
        }
        template <typename T = const char *>
        void Logger::Writeln(T message, byte state = States::Debug)
        {
            if (this->m_state <= state && m_serial)
            {
                Serial.println(message);
            }
        }

        const char *CurrentState();
    };
} // namespace Logger
