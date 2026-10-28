// ============================================================================
// Window.cpp
//
// Loose wrapper class that handles GLFW Window lifecycle and events
// ============================================================================

#include "Window.hpp"
#include "../utils/Logger.hpp"

#include <stdexcept>

Window::Window(int width, int height, const char* title)
{
    InitWindow(width, height, title);
}

Window::~Window()
{
    DestroyWindow();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::InitWindow(int width, int height, const char* title)
{
    if (!glfwInit())
    {
        throw std::runtime_error("GLFW Init Failed");
    }

    Window::window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Create Window Failed");
    }

    glfwMakeContextCurrent(window);
}

void Window::DestroyWindow()
{
    glfwDestroyWindow(window);
    window = nullptr;

    glfwTerminate();
}