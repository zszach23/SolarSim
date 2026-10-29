// ============================================================================
// Application.hpp
//
// Defines the lifecycle for the application
// ============================================================================

#pragma once

#include "Window.hpp"

class Application
{
public:

public:

    Application(int windowWidth = 640, int windowHeight = 480, const char *windowTitle = "App");
    ~Application();

    void Run();

private:

    Window window;

private:

};