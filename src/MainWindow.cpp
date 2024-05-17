#include "MainWindow.hpp"
#include <GL/glew.h>
#include <iostream>

bool Window::init()
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

    m_display = SDL_CreateWindow("OpenGL Window", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK,
                                 ScreenWidth, ScreenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    OpenGLContext = SDL_GL_CreateContext(m_display);

    // glew initialize;
    if (glewInit() != GLEW_OK)
    {
        std::cout << ("Error in glewInit\n");

        return false;
    }

    GetOpenGLVersionInfo();

    SDL_WarpMouseInWindow(m_display, ScreenWidth / 2, ScreenHeight / 2);
    
    // This function hides basic cursor Windows. Default value is false
    // SDL_SetRelativeMouseMode(SDL_FALSE);

    return true;
}

void Window::GetOpenGLVersionInfo()
{
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

Window::Window()
{
}

Window::~Window()
{
}