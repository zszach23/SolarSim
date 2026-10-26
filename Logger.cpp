// ============================================================================
// Logger.cpp
//
// Utility class to handle uniform logging
// ============================================================================

#include "Logger.hpp"
#include <iostream>

void Logger::LogEvent(LogType type, const char* description)
{
    std::ostream& out = (type == ERROR || type == WARNING) ? std::cerr : std::cout;
    out << GetColor(type) << "[" << GetLabel(type) << "] "
        << description << Reset() << '\n';
}

void Logger::LogGLFWError(int errorCode, const char* description)
{
    Logger::LogEvent(ERROR, description);
}

const char* Logger::GetColor(LogType type)
{
    switch (type)
    {
        case DEBUG:   return "\033[36m"; // cyan
        case INFO:    return "\033[32m"; // green
        case WARNING: return "\033[33m"; // yellow
        case ERROR:   return "\033[31m"; // red
    }
    return "";
}

const char* Logger::GetLabel(LogType type)
{
    switch (type)
    {
        case DEBUG:   return "DEBUG";
        case INFO:    return "INFO";
        case WARNING: return "WARNING";
        case ERROR:   return "ERROR";
    }
    return "";
}

const char* Logger::Reset() 
{
    return "\033[0m"; 
}