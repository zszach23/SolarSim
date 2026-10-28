// ============================================================================
// Window.hpp
//
// Loose wrapper class that handles GLFW Window lifecycle and events
// ============================================================================

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:

public:
    Window(int width, int height, const char* title);
    ~Window();

    bool ShouldClose();
    void PollEvents();
    void SwapBuffers();
    void ProcessInput();

private:
    GLFWwindow* window;

private:
    void InitWindow(int width, int height, const char* title);
    void DestroyWindow();

    static void OnResize(GLFWwindow* window, int newWidth, int newHeight);
};