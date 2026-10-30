// ============================================================================
// Application.cpp
//
// Defines the lifecycle for the application
// ============================================================================

#include "Application.hpp"
#include "../render/HelloTriangle.hpp"
#include "../render/HelloCircle.hpp"

Application::Application(int windowWidth, int windowHeight, const char* windowTitle)
    : window(windowWidth, windowHeight, windowTitle)
{
    
}

Application::~Application()
{
    
}

void Application::Run()
{
    HelloCircle circle;

    while (!window.ShouldClose())
    {

        glClearColor(0.0f, 0.0f, 0.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        circle.Draw();
        window.ProcessInput();
        window.SwapBuffers();
        window.PollEvents();
    }
}