#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <OpenGL.h>
#include <stdexcept>
#include <string>
#include <vector>

#include "Entity.h"
#include "Triangle.h"

void OpenGL::Run()
{
    constexpr int width = 1000.0;
    constexpr int height = 1000.0;
    if (!glfwInit())
    {
        SetOutcome("Cannot initialize GLFW");
        return;
    }

    const auto window = glfwCreateWindow(width, height, "OpenGL MRE", nullptr, nullptr);
    if (!window)
    {
        SetOutcome("Cannot create window");
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        SetOutcome("Cannot initialize GLEW");
        return;
    }

    constexpr double scaleFactorX = 1000.0 / width;
    constexpr double scaleFactorY = 1000.0 / height;

    std::vector<Entity*> m_entities;
    m_entities.reserve(2);

    std::vector<double> positions1;
    positions1.reserve(6);
    positions1.emplace_back(-0.6 * scaleFactorX);
    positions1.emplace_back(-0.6 * scaleFactorY);
    positions1.emplace_back(-0.6 * scaleFactorX);
    positions1.emplace_back(0.4 * scaleFactorY);
    positions1.emplace_back(0.4 * scaleFactorX);
    positions1.emplace_back(-0.6 * scaleFactorX);
    std::vector<float> colors1;
    colors1.reserve(4);
    colors1.emplace_back(1.0f);
    colors1.emplace_back(0.0f);
    colors1.emplace_back(0.0f);
    colors1.emplace_back(1.0f);
    Entity* firstTriangle = new Triangle(positions1, colors1);

    std::vector<double> positions2;
    positions2.reserve(6);
    positions2.emplace_back(0.6 * scaleFactorX);
    positions2.emplace_back(0.6 * scaleFactorY);
    positions2.emplace_back(-0.4 * scaleFactorX);
    positions2.emplace_back(0.6 * scaleFactorY);
    positions2.emplace_back(0.6 * scaleFactorX);
    positions2.emplace_back(-0.4 * scaleFactorX);
    std::vector<float> colors2;
    colors2.reserve(4);
    colors2.emplace_back(0.0f);
    colors2.emplace_back(0.0f);
    colors2.emplace_back(1.0f);
    colors2.emplace_back(1.0f);
    Entity* secondTriangle = new Triangle(positions2, colors2);

    m_entities.emplace_back(firstTriangle);
    m_entities.emplace_back(secondTriangle);

    while (true)
    {
        // Set the clear color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for (const auto entity : m_entities)
        {
            entity->Loop();
        }

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
}

//---------------------------------------------------------------

void OpenGL::SetOutcome(const std::string& errorMessage)
{
    throw std::runtime_error(errorMessage.c_str());
}
