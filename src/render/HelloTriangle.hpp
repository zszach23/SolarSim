// ============================================================================
// HelloTriangle.hpp
//
// Get a triangle to render on screen
// ============================================================================

#pragma once

class HelloTriangle
{
public:

public:
    HelloTriangle();
    ~HelloTriangle();

    void Draw();

private:

    /// @brief 3 vertices of a triangle, clamped between [-1, 1]
    const float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    /// @brief Vertex Buffer Object: Stores a large number of vertices in GPU memory
    unsigned int VBO;

    /// @brief Vertex Array Object: Objects that store vertex attributes
    unsigned int VAO;

    /// @brief Shader Program Object: Final linked version of multiple shaders combined
    unsigned int shaderProgram;

    /// @brief Vertex Shader: Transform 3D coordinates into OpenGL 3D coordinates
    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    /// @brief Fragment Shader: Calculate the final color of a pixel
    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

private:

    /// @brief Handles the setup of Vertex Buffer and Arrays and their attributes
    void SetVertexData();
    unsigned int SetVertexShader();
    unsigned int SetFragmentShader();
    unsigned int SetShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);

};