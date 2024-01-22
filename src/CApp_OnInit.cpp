#include "CApp.h"
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
    const std::vector<GLfloat> vertexData{
        // 0 vertex
        -0.5f, -0.5f, 0.0f, // left vertex position
        1.0f, 0.0f, 0.0f,   // color
        // 1 vertex
        0.5f, -0.5f, 0.0f, // right vertex position
        0.0f, 1.0f, 0.0f,  // color
        // 2 vertex
        -0.5f, 0.5f, 0.0f, // top vertex position
        0.0f, 0.0f, 1.0f,  // color
        // 3 vertex
        0.5f, 0.5f, 0.0f, // top vertex position
        0.0f, 0.0f, 1.0f, // color

    };

    glGenVertexArrays(1, &gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);

    glGenBuffers(1, &gVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);

    const std::vector<GLuint> indexBufferData{ 2, 0, 1, 3, 2, 1 };
    glGenBuffers(1, &gIndexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIndexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferData.size() * sizeof(GLfloat), indexBufferData.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3));

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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
