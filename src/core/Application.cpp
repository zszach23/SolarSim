// ============================================================================
// Application.cpp
//
// Defines the lifecycle for the application
// ============================================================================

#include "Application.hpp"
#include "../render/HelloTriangle.hpp"
#include "../render/HelloCircle.hpp"
#include "../render/HelloSphere.hpp"

Application::Application(int windowWidth, int windowHeight, const char* windowTitle)
    : window(windowWidth, windowHeight, windowTitle)
{
    
}

Application::~Application()
{
    
}

void Application::Run()
{
    HelloSphere sphere;
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_PROGRAM_POINT_SIZE);

    while (!window.ShouldClose())
    {

        glClearColor(0.0f, 0.0f, 0.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        sphere.Draw();
        window.ProcessInput();
        window.SwapBuffers();
        window.PollEvents();
    }
}