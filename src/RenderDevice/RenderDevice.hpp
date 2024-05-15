#pragma once

#include <GL/glew.h>
#include <string>

class RenderDevice
{
public:
    RenderDevice();
    ~RenderDevice();

public:
    void init();
    void destroy();
    void draw(GLfloat vertexData[]);

public:
    GLuint VertexArrayObject = 0;
    GLuint VertexBufferObject = 0;
    GLuint m_shaderProgram = 0;

private:
    void CreateGraphicsPiepline();

    GLuint CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource);

    GLuint CompileShader(GLuint type, const std::string& source);

    std::string LoadShaderAsString(const std::string& filename);
};