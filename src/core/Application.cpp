// ============================================================================
// Application.cpp
//
// Defines the lifecycle for the application
// ============================================================================

#include "Application.hpp"
#include "../render/HelloTriangle.hpp"

Application::Application(int windowWidth, int windowHeight, const char* windowTitle)
    : window(windowWidth, windowHeight, windowTitle)
{
    
}

Application::~Application()
{
    
}

void Application::Run()
{
    HelloTriangle triangle;

    while (!window.ShouldClose())
    {
        triangle.Draw();
        window.ProcessInput();
        window.SwapBuffers();
        window.PollEvents();
    }
}

void Application::Render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}