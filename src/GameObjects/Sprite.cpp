#include "Sprite.hpp"




std::vector<GLfloat> Sprite::render(std::vector<GLfloat> m_initialPosition, const GLfloat& spriteSize)
{
    std::vector<GLfloat> vertexes;

    vertexes[0] = m_initialPosition[0]; // x
    vertexes[1] = m_initialPosition[1]; // y
    vertexes[2] = m_initialPosition[2]; // z

    vertexes[3] = m_initialPosition[0] + spriteSize;
    vertexes[4] = m_initialPosition[1];
    vertexes[5] = m_initialPosition[2];

    vertexes[6] = m_initialPosition[0] + spriteSize;
    vertexes[7] = m_initialPosition[1] + spriteSize;
    vertexes[8] = m_initialPosition[2];

    vertexes[9] = m_initialPosition[0];
    vertexes[10] = m_initialPosition[1] + spriteSize;
    vertexes[11] = m_initialPosition[2];

    return vertexes;
}
