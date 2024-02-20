#include "CApp.h"
#include <SOIL/SOIL.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    Surf_Display = SDL_CreateWindow("OpenGL Window", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK, gScreenWidth, gScreenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    gOpenGLContext = SDL_GL_CreateContext(Surf_Display);

    // glew initialize;
    if (glewInit() != GLEW_OK)
    {
        std::cout << ("Error in glewInit\n");

        return 1;
    }

    GetOpenGLVersionInfo();
    VertexSpecification();
    CreateGraphicsPiepline();
    glUseProgram(gGraphicsPieplineShaderProgram);

    SDL_WarpMouseInWindow(Surf_Display, gScreenWidth / 2, gScreenHeight / 2);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    return true;
}

void CApp::VertexSpecification()
{
    int width, height;
    unsigned char* image = SOIL_load_image("D:/learn/c++/opengl_sdl2/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    const std::vector<GLfloat> vertexData{
        // 0 vertex
        -0.5f, -0.5f, 0.0f, // left vertex position
        // 1.0f, 0.0f, 0.0f,   // color
        0.0f, 0.0f, // texture coordinates
        // 1 vertex
        0.5f, -0.5f, 0.0f, // right vertex position
        // 0.0f, 1.0f, 0.0f,  // color
        1.0f, 0.0f, // texture coordinates
        // 2 vertex
        -0.5f, 0.5f, 0.0f, // top vertex position
        // 0.0f, 0.0f, 1.0f,  // color
        0.0f, 1.0f, // texture coordinates
        // 3 vertex
        0.5f, 0.5f, 0.0f, // top vertex position
        // 1.0f, 1.0f, 0.0f, // color
        1.0f, 1.0f, // texture coordinates

        // 4 vertex
        0.5f, -0.5f, -1.0f, // right vertex position
        // 1.0f, 0.0f, 0.0f,   // color
        0.0f, 0.0f, // texture coordinates
        // 5 vertex
        0.5f, 0.5f, -1.0f, // top vertex position
        // 0.0f, 1.0f, 0.0f,  // color
        0.0f, 1.0f, // texture coordinates
        // 6 vertex
        -0.5f, 0.5f, -1.0f, // top vertex position
        // 0.0f, 0.0f, 1.0f,   // color
        1.0f, 1.0f, // texture coordinates
        // 7 vertex
        -0.5f, -0.5f, -1.0f, // left vertex position
        // 1.0f, 1.0f, 0.0f,    // color
        1.0f, 0.0f, // texture coordinates
    };

    glGenVertexArrays(1, &gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);

    glGenBuffers(1, &gVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);

    const std::vector<GLuint> indexBufferData{ 2, 0, 1, 3, 2, 1,
                                               1, 4, 5, 3, 1, 5,
                                               5, 4, 7, 6, 5, 7,
                                               7, 0, 2, 6, 7, 2,
                                               2, 3, 5, 6, 2, 5,
                                               0, 7, 4, 1, 0, 4 };
    glGenBuffers(1, &gIndexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIndexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferData.size() * sizeof(GLuint), indexBufferData.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);

    // glEnableVertexAttribArray(1);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (void*)(sizeof(GLfloat) * 3));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)(sizeof(GLfloat) * 3));

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

GLuint CApp::CompileShader(GLuint type, const std::string& source)
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

std::string CApp::LoadShaderAsString(const std::string& filename)
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

GLuint CApp::CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource)
{
    GLuint programObject = glCreateProgram();
    GLuint myVertexShader = CompileShader(GL_VERTEX_SHADER, vertexshadersource);
    GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentshadersource);
    glAttachShader(programObject, myVertexShader);
    glAttachShader(programObject, myFragmentShader);
    glLinkProgram(programObject);

    glValidateProgram(programObject);

    return programObject;
}

void CApp::CreateGraphicsPiepline()
{
    std::string vertexShaderSource = LoadShaderAsString("D:/learn/c++/opengl_sdl2/shaders/vert.glsl");
    std::string fragmentShaderSource = LoadShaderAsString("D:/learn/c++/opengl_sdl2/shaders/frag.glsl");

    gGraphicsPieplineShaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
}
