// ============================================================================
// Window.hpp
//
// Loose wrapper class that handles GLFW Window lifecycle and events
// ============================================================================

#pragma once

#include <GLFW/glfw3.h>
#include "AppContext.hpp"

class Window
{
public:

private:
    GLFWwindow* window;

public:
    Window(const AppContext&, int width, int height, const char* title);
    ~Window();

    bool ShouldClose();
    void PollEvents();

private:
    void InitWindow(int width, int height, const char* title);
    void DestroyWindow();

};