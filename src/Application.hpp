#pragma once

#include "MainWindow.hpp"
#include "RenderDevice/RenderDevice.hpp"

#include <gl/gl.h>
#include <memory>

class Page;

class Application
{
public:
    GLuint vertexbuffer;

    bool m_isRunning;
    Window window;
    SDL_Event event;

public:
    Application();

public:
    bool init();
    void run();
    void destroy();

private:
    bool proccessInput();
    void update(float dt);
    void render();

private:
    const Uint8* state = SDL_GetKeyboardState(NULL);
    Page* m_currentPage = nullptr;
    std::unique_ptr<RenderDevice> m_renderDevice;

private:
    Page* createGamePage();
};
