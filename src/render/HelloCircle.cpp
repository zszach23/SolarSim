// ============================================================================
// HelloCircle
//
// Render a circle on the screen
// ============================================================================

#include "HelloCircle.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

HelloCircle::HelloCircle()
    : segments(100)
{
    unsigned int vertexShader = SetVertexShader();
    unsigned int fragmentShader = SetFragmentShader();
    shaderProgram = SetShaderProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GenerateVertices();
    SetVertexData();
}

HelloCircle::~HelloCircle()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
}

void HelloCircle::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);
}

void HelloCircle::GenerateVertices()
{
    vertices.push_back(0.0f); // X Origin
    vertices.push_back(0.0f); // Y Origin

    for (int i = 0; i <= segments; i++)
    {
        float theta = 2 * M_PI * i / segments;
        vertices.push_back(radius * glm::cos(theta));
        vertices.push_back(radius * glm::sin(theta));
    }
}

void HelloCircle::SetVertexData()
{
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

unsigned int HelloCircle::SetVertexShader()
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    return vertexShader;
}

unsigned int HelloCircle::SetFragmentShader()
{
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    return fragmentShader;
}

unsigned int HelloCircle::SetShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    return shaderProgram;
} 