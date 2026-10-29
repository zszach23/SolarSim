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

    /// @brief Checks the GLFW Should Window Close Flag
    /// @return Whether the Window should close
    bool ShouldClose();

    /// @brief Polls IO events in queue
    void PollEvents();

    /// @brief Swaps front and back buffers of window
    void SwapBuffers();

    /// @brief Handles Input events
    void ProcessInput();

private:
    GLFWwindow* window;

private:
    void InitWindow(int width, int height, const char* title);
    void DestroyWindow();

    static void OnResize(GLFWwindow* window, int newWidth, int newHeight);
};