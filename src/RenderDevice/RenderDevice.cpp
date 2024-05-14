#include "RenderDevice.hpp"

RenderDevice::RenderDevice()
{
}

RenderDevice::~RenderDevice()
{
}

void RenderDevice::init()
{
    // generate VAO
    glGenVertexArrays(1, &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);

    // generate VBO
    glGenBuffers(1, &VertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
    // glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);

    // set up VAO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    // set up lightVAO
    // glGenVertexArrays(1, &lightVAO);
    // glBindVertexArray(lightVAO);
    // glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
}

void RenderDevice::destroy()
{
}

void RenderDevice::draw(Vertex vertexBuffer[], uint32_t indexBuffer[])
{
}
