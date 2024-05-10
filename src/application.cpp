#include "Application.h"

#include "Page.hpp"

#include <SDL2/SDL.h>

Application::Application()
    : m_isRunning(true)
{
    m_renderDevice = std::make_unique<RenderDevice>(new RenderDevice());
}

bool Application::init()
{
    return false;
}

void Application::destroy()
{
    m_renderDevice.reset();
    // destroy impl
}

void Application::run()
{
    constexpr float defaultDeltaTime = 1.0f / 60.0f;
    while (m_isRunning)
    {
        proccessInput();
        update(defaultDeltaTime);
        render();
    }
}



bool Application::proccessInput()
{
    SDL_Event event;

    while (counter > 0 && SDL_PollEvent(&event))
    {
        m_currentPage->onInput(event);
    }
}

void Application::update(float dt)
{
    m_currentPage->update(dt);
}

void Application::render()
{
    m_currentPage->render(m_renderDevice);
    SDL_GL_SwapWindow(Display);
}