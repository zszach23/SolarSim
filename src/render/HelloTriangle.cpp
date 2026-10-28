// ============================================================================
// HelloTriangle
//
// Get a triangle to render on screen
// ============================================================================

#include "HelloTriangle.hpp"
#include "../utils/Logger.hpp"

#include <GL/glew.h>

HelloTriangle::HelloTriangle()
{
    unsigned int vertexShader = SetVertexShader();
    unsigned int fragmentShader = SetFragmentShader();
    shaderProgram = SetShaderProgram(vertexShader, fragmentShader);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    SetBuffer();
}

HelloTriangle::~HelloTriangle()
{

}

void HelloTriangle::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void HelloTriangle::SetBuffer()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

unsigned int HelloTriangle::SetVertexShader()
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        Logger::LogEvent(ERROR, infoLog);
    }
    else
    {
        Logger::LogEvent(INFO, "Vertex Shader Compiled");
    }

    return vertexShader;
}

unsigned int HelloTriangle::SetFragmentShader()
{
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        Logger::LogEvent(ERROR, infoLog);
    }
    else
    {
        Logger::LogEvent(INFO, "Fragment Shader Compiled");
    }

    return fragmentShader;
}

unsigned int HelloTriangle::SetShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    unsigned int shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        Logger::LogEvent(ERROR, infoLog);
    }
    else
    {
        Logger::LogEvent(INFO, "Shader Program Linked");
    }

    return shaderProgram;
}