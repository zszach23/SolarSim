// ============================================================================
// HelloCircle
//
// Render a circle on the screen
// ============================================================================

#include <vector>

class HelloCircle
{
public:

public:
    HelloCircle();
    ~HelloCircle();

    void Draw();

private:
    unsigned int VBO;
    unsigned int VAO;
    unsigned int shaderProgram;

    std::vector<float> vertices;
    const int segments;
    const float radius = 0.5f;

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

private:
    void GenerateVertices();
    void SetVertexData();
    unsigned int SetVertexShader();
    unsigned int SetFragmentShader();
    unsigned int SetShaderProgram(unsigned int vertexShader, unsigned int fragmentShader); 
};