#pragma once

#include <GL/glew.h>
#include <string>
#include <vector>

class RenderDevice
{
public:
    RenderDevice();
    ~RenderDevice();

public:
    void init();
    void destroy();
    void draw(std::vector<GLfloat> m_vertexData);

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