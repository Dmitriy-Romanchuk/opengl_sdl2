#include "Sprite.hpp"

std::vector<GLfloat> Sprite::render(std::vector<GLfloat> m_initialPosition, const GLfloat& spriteSize)
{
    std::vector<GLfloat> vertexes{

        m_initialPosition[0], m_initialPosition[1], m_initialPosition[2],

        1.0f, 1.0f,

        m_initialPosition[0] + spriteSize, m_initialPosition[1], m_initialPosition[2],

        1.0f, 0.0f,

        m_initialPosition[0] + spriteSize, m_initialPosition[1] + spriteSize, m_initialPosition[2],

        0.0f, 0.0f,

        m_initialPosition[0], m_initialPosition[1] + spriteSize, m_initialPosition[2],

        0.0f, 1.0f
    };

    return vertexes;
}
