#include "RenderDevice/RenderDevice.hpp"

#include <fstream>
#include <iostream>

RenderDevice::RenderDevice()
{
}

RenderDevice::~RenderDevice()
{
}

void RenderDevice::draw(const GLfloat* data, size_t size)
{
    glClearColor(0.1f, 0.5f, 0.1f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glUseProgram(m_shaderProgram);
    glBindVertexArray(m_vertexArrayObject);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), data, GL_STATIC_DRAW);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void RenderDevice::destroy()
{
}

void RenderDevice::init()
{
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, 800, 800);

    // TODO: Вынести в отдельный метод------------------
    glClearColor(0.1f, 0.5f, 0.1f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    // -------------------------------------------------

    CreateGraphicsPiepline();
    // generate VAO
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    // generate VBO
    glGenBuffers(1, &m_vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
    // glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(GLfloat), m_vertexData.data(), GL_STATIC_DRAW);

    // set up VAO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)(sizeof(GLfloat) * 3));

    const std::vector<GLuint> indexBufferData{ 0, 1, 3, 1, 2, 3 };
    glGenBuffers(1, &m_indexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferData.size() * sizeof(GLfloat), indexBufferData.data(), GL_STATIC_DRAW);

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    stbi_image_free(image);
    glBindTexture(GL_TEXTURE_2D, 0);
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
            std::cout << line << std::endl;
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
    std::string vertexShaderSource = LoadShaderAsString("shaders/vert.glsl");
    std::string fragmentShaderSource = LoadShaderAsString("shaders/frag.glsl");

    m_shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
}
