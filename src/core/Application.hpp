// ============================================================================
// Application.hpp
//
//
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

    void Render();

private:

    Window window;

private:

};