// ============================================================================
// GLFWContext.cpp
//
// Defines lifecycle of GLFW
// ============================================================================

#include "AppContext.hpp"
#include "../core/Logger.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

bool AppContext::IsActive = false;

AppContext::AppContext()
{
    if (IsActive)
    {
        throw std::logic_error("Context Already Created");
    }

    glfwSetErrorCallback(Logger::LogGLFWError);

    if (!glfwInit())
    {
        throw std::runtime_error("GLFW Init Failed");
    }

    IsActive = true;
    Logger::LogEvent(INFO, "Context Initialized");
}

AppContext::~AppContext()
{
    glfwTerminate();
    IsActive = false;

    Logger::LogEvent(INFO, "Context Terminated");
}