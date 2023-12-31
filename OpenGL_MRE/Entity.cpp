#include "GL/glew.h"

#include <Entity.h>
#include <iostream>

Entity::Entity(const unsigned int count, const unsigned int mode)
    : m_vertexShaderSource(nullptr), m_fragmentShaderSource(nullptr), m_count(count), m_fragmentShader(0), m_mode(mode),
    m_shaderProgram(0), m_VAO(0), m_VBO(0), m_vertexShader(0)
{
}

Entity::~Entity()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteProgram(m_shaderProgram);
}

void Entity::Loop()
{
    glUseProgram(m_shaderProgram);
    CheckProgramLinking(m_shaderProgram);
    Color();
    glBindVertexArray(m_VAO);
    CheckOpenGLError("Before draw");
    glDrawArrays(m_mode, 0, m_count);
}

// Function to check shader compilation status
void Entity::CheckShaderCompilation(const unsigned int shader) {
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation error:\n" << infoLog << '\n';
    }
}

// Function to check program linking status
void Entity::CheckProgramLinking(const unsigned int program) {
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Program linking error:\n" << infoLog << '\n';
    }
}

void Entity::CheckOpenGLError(const char* checkpoint) {
    if (const unsigned int error = glGetError(); error != GL_NO_ERROR) {
        std::cerr << "OpenGL error (" << checkpoint << "): " << error << '\n';
    }
}
