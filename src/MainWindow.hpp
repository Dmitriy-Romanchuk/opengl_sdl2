#pragma once

#include <SDL.h>

class Window
{
private:
    int ScreenWidth = 800;
    int ScreenHeight = 800;
public:
    SDL_Window* m_display = nullptr;
    SDL_GLContext OpenGLContext = nullptr;

public:
    Window();
    ~Window();
    bool init();
    void destroy();
    void GetOpenGLVersionInfo();
};




