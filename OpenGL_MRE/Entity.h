#pragma once
#include <vector>

class Entity
{
public:
    Entity(unsigned count, unsigned mode);

    static void CheckShaderCompilation(unsigned shader);
    static void CheckProgramLinking(unsigned program);
    static void CheckOpenGLError(const char* checkpoint);
    virtual void Color() = 0;
    void Loop();

protected:
    ~Entity();

    unsigned int m_count;
    unsigned int m_mode;
    unsigned int m_VAO;
    unsigned int m_VBO;
    std::vector<float> m_colors;

    static const char* m_vertexShaderSource;
    static const char* m_fragmentShaderSource;
    static unsigned int m_fragmentShader;
    static unsigned int m_vertexShader;
    static unsigned int m_shaderProgram;
};
