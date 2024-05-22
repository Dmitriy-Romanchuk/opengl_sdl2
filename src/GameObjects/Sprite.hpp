#pragma once
#include "Application.hpp"

//#include <gl/gl.h>
#include <vector>

class Sprite
{
public:
    std::vector<GLfloat> render(std::vector<GLfloat> m_initialPosition, const GLfloat& spriteSize);

};