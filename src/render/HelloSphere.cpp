// ============================================================================
// HelloSphere
//
// Render a sphere on the screen
// ============================================================================

#include "HelloSphere.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <vector>

HelloSphere::HelloSphere()
    : stacks(100), sectors(100)
{
    unsigned int vertexShader = SetVertexShader();
    unsigned int fragmentShader = SetFragmentShader();
    shaderProgram = SetShaderProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GenerateVertices();
    SetVertexData();
}

HelloSphere::~HelloSphere()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
}

void HelloSphere::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, vertices.size() / 3);
}

void HelloSphere::GenerateVertices()
{
    for (int i = 0; i <= stacks; i++)
    {
        float phi = glm::pi<float>() * i / stacks;
        float ringRadius = radius * glm::sin(phi);

        float y = radius * glm::cos(phi);

        for (int j = 0; j <= sectors; j++)
        {
            float theta = 2 * glm::pi<float>() * j / sectors;

            float x = ringRadius * glm::cos(theta);
            float z = ringRadius * glm::sin(theta);

            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);  
        }
    }
}

void HelloSphere::SetVertexData()
{
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

unsigned int HelloSphere::SetVertexShader()
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    return vertexShader;
}

unsigned int HelloSphere::SetFragmentShader()
{
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    return fragmentShader;
}

unsigned int HelloSphere::SetShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    return shaderProgram;
}