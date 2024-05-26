#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <string>
#include <vector>

class RenderDevice
{
public:
    RenderDevice();
    ~RenderDevice();

public:
    void draw(std::vector<GLfloat> m_vertexData);
    void destroy();
    void init();

public:
    GLuint m_vertexArrayObject = 0;
    GLuint m_vertexBufferObject = 0;
    GLuint m_shaderProgram = 0;
    GLuint m_indexBufferObject = 0;
    GLuint m_texture;

private:
    int width, height;
    unsigned char* image = SOIL_load_image("container.jpg", &width, &height, 0, SOIL_LOAD_RGB);

private:
    void CreateGraphicsPiepline();

    GLuint CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource);

    GLuint CompileShader(GLuint type, const std::string& source);

    std::string LoadShaderAsString(const std::string& filename);
};