// ============================================================================
// SolarSim.cpp
//
// 
// ============================================================================

#include <GLFW/glfw3.h>
#include "Logger.hpp"

void RunSimulation();
void LogGLFWError(int errorCode, const char* description);

int main(void)
{
    RunSimulation();

    return 0;
}

void RunSimulation()
{
    glfwSetErrorCallback(Logger::LogGLFWError);

    if (!glfwInit())
        return;

    glfwTerminate();
}