// ============================================================================
// HelloSphere
//
// Render a sphere on screen
// ============================================================================

#include <vector>

class HelloSphere
{
public:

public:
    HelloSphere();
    ~HelloSphere();

    void Draw();

private:
    std::vector<float> vertices;
    const int stacks;
    const int sectors;
    const float radius = 0.5f;

    unsigned int VBO;
    unsigned int VAO;

    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        void main()
        {
            gl_Position = vec4(aPos, 1.0);
            gl_PointSize = 3.0;
        }
        )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0, 1.0, 1.0, 1.0);
        }
        )";
        
    unsigned int shaderProgram;

private:
    void GenerateVertices();
    void SetVertexData();
    unsigned int SetVertexShader();
    unsigned int SetFragmentShader();
    unsigned int SetShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
};