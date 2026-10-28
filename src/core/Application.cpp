// ============================================================================
// Application.cpp
//
// Defines the lifecycle for the application
// ============================================================================

#include "Application.hpp"

Application::Application()
    : window(640, 480, "Solar Sim")
{
    
}

Application::~Application()
{
    
}

void Application::Run()
{
    while (!window.ShouldClose())
    {
        window.PollEvents();


    }
}