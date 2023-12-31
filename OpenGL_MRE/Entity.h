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
    virtual void CompileShaders() = 0;
    void Loop();

protected:
    ~Entity();

    const char* m_vertexShaderSource;
    const char* m_fragmentShaderSource;
    unsigned int m_count;
    unsigned int m_fragmentShader;
    unsigned int m_mode;
    unsigned int m_shaderProgram;
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_vertexShader;
    std::vector<float> m_colors;
};
