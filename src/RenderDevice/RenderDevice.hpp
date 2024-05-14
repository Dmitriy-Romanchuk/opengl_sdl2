#pragma once

// #include "Application.hpp"
#include "pages/Page.hpp"

#include <GL/glew.h>
#include <cstdint>

class Vertex;

class RenderDevice
{
public:
    RenderDevice();
    ~RenderDevice();

public:
    void init();
    void destroy();

    void draw(Vertex vertexBuffer[], uint32_t indexBuffer[]);

public:
    GLuint VertexArrayObject = 0;
    GLuint VertexBufferObject = 0;
};