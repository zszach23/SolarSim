// ============================================================================
// Application.hpp
//
//
// ============================================================================

#pragma once

#include "AppContext.hpp"
#include "Window.hpp"

class Application
{
public:

private:
    AppContext context;
    Window window;

public:
    Application();
    ~Application();
    void Run();

private:
    void Init();
    void Terminate();
};