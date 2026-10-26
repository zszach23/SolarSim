// ============================================================================
// Application.cpp
//
// 
// ============================================================================

#include "Application.hpp"

Application::Application()
    : context()
    , window(context, 640, 480, "Solar Sim")
{

}

Application::~Application()
{
    Terminate();
}

void Application::Run()
{
    while (!window.ShouldClose())
    {
        window.PollEvents();
    }
}

void Application::Terminate()
{

}