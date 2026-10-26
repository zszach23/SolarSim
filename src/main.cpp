// ============================================================================
// main.cpp
// ============================================================================

#include "app/Application.hpp"
#include "core/Logger.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    try
    {
        Application app;
        app.Run();
    }
    catch(const std::exception& e)
    {
        Logger::LogEvent(ERROR, e.what());
    }

    return 0;
}