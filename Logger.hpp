// ============================================================================
// Logger.hpp
//
// Utility class to handle uniform logging
// ============================================================================

enum LogType
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger
{
public:
    static void LogEvent(LogType type, const char* description);
    static void LogGLFWError(int errorCode, const char* description);

private:
    static const char* GetColor(LogType type);
    static const char* GetLabel(LogType type);
    static const char* Reset();
};