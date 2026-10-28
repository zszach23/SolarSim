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
    glfwSetErrorCallback(Logger::LogGLFWError);

    if (!glfwInit())
    {
        throw std::runtime_error("GLFW Init Failed");
    }

    InitWindow(width, height, title);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw std::runtime_error("GLEW Initialization Failed");
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, OnResize);
}

Window::~Window()
{
    DestroyWindow();
    glfwTerminate();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void Window::ProcessInput()
{
    
}

void Window::InitWindow(int width, int height, const char* title)
{
    // Configure OpenGL GLFW Window Options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
}

void Window::OnResize(GLFWwindow* window, int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
}