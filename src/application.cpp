#include "Application.hpp"

#include <SDL2/SDL.h>

Application::Application()
    : m_isRunning(true)
{
    // m_renderDevice = std::make_unique<RenderDevice>(m_renderDevice);
}

bool Application::init()
{
    return window.Init();
}

void Application::destroy()
{
    // m_renderDevice.reset();
    //  destroy impl
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
    while (SDL_PollEvent(&event))
    {
        if (state[SDL_SCANCODE_ESCAPE])
        {
            m_isRunning = false;
        }
        // m_currentPage->onInput(event);
    }
    return true;
}

void Application::update(float dt)
{
    // m_currentPage->update(dt);
}

void Application::render()
{
    // m_currentPage->render(m_renderDevice);
    SDL_GL_SwapWindow(window.m_display);
}
