#include "RenderDevice/RenderDevice.hpp"

#include <fstream>

RenderDevice::RenderDevice()
{
}

RenderDevice::~RenderDevice()
{
}

void RenderDevice::init()
{
    CreateGraphicsPiepline();
}

void RenderDevice::destroy()
{
}

void RenderDevice::draw(std::vector<GLfloat> m_vertexData)
{
    // generate VAO
    glGenVertexArrays(1, &VertexArrayObject);
    glBindVertexArray(VertexArrayObject);

    // generate VBO
    glGenBuffers(1, &VertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(GLfloat), m_vertexData.data(), GL_STATIC_DRAW);

    // set up VAO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

GLuint RenderDevice::CompileShader(GLuint type, const std::string& source)
{
    GLuint shaderObject;
    if (type == GL_VERTEX_SHADER)
    {
        shaderObject = glCreateShader(GL_VERTEX_SHADER);
    }
    else if (type == GL_FRAGMENT_SHADER)
    {
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    const char* src = source.c_str();
    glShaderSource(shaderObject, 1, &src, nullptr);
    glCompileShader(shaderObject);

    return shaderObject;
}

std::string RenderDevice::LoadShaderAsString(const std::string& filename)
{
    std::string result = "";
    std::string line = "";
    std::ifstream myFile(filename.c_str());
    if (myFile.is_open())
    {
        while (std::getline(myFile, line))
        {
            result += line + '\n';
        }
        myFile.close();
    }

    return result;
}

GLuint RenderDevice::CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource)
{
    GLuint myVertexShader = CompileShader(GL_VERTEX_SHADER, vertexshadersource);
    GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentshadersource);

    GLuint programObject = glCreateProgram();
    glAttachShader(programObject, myVertexShader);
    glAttachShader(programObject, myFragmentShader);

    glLinkProgram(programObject);
    glValidateProgram(programObject);

    return programObject;
}

void RenderDevice::CreateGraphicsPiepline()
{
    std::string vertexShaderSource = LoadShaderAsString("C:/Users/37529/Desktop/Dima/C++/opengl_sdl2/shaders/vert.glsl");
    std::string fragmentShaderSource = LoadShaderAsString("C:/Users/37529/Desktop/Dima/C++/opengl_sdl2/shaders/frag.glsl");

    m_shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
}
