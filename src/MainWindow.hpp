#pragma once

#include <SDL2/SDL.h>

class Window
{
private:
    int ScreenWidth = 800;
    int ScreenHeight = 800;
public:
    SDL_Window* Display;
    SDL_GLContext OpenGLContext = nullptr;

public:
    Window();
    ~Window();
    bool Init();
    void GetOpenGLVersionInfo();
};




