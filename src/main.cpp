// ============================================================================
// main
//
// Entry point into application
// ============================================================================

#include "core/Application.hpp"
#include "utils/Logger.hpp"

#include <stdexcept>

#define INIT_WIDTH 640
#define INIT_HEIGHT 480
#define TITLE "Solar Sim"

int main(void)
{
    try
    {
        Application app(INIT_WIDTH, INIT_HEIGHT, TITLE);
        app.Run();
    }
    catch(const std::exception& e)
    {
        Logger::LogEvent(ERROR, e.what());
    }

    return 0;
}