// #ifndef _CAPP_H_
// #define _CAPP_H_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class CApp
{
public:
    bool Running;
    SDL_Window* Surf_Display;
    SDL_GLContext gOpenGLContext = nullptr;
    GLuint gVertexArrayObject = 0;
    GLuint gVertexBufferObject = 0;
    GLuint gGraphicsPieplineShaderProgram = 0;
    GLuint vertexbuffer;

public:
    CApp();

    int OnExecute();

public:
    bool OnInit();

    void VertexSpecification();

    void CreateGraphicsPiepline();

    GLuint CreateShaderProgram(const std::string& vs, const std::string& fs);

    GLuint CompileShader(GLuint type, const std::string& source);

    std::string LoadShaderAsString(const std::string& filename);

    GLuint gIndexBufferObject = 0;

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();

    void OnCleanup();

    void GetOpenGLVersionInfo()
    {
        std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
        std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
        std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
        std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    }
};

// #endif