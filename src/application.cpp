#include "Application.hpp"
#include "Pages/GamePage.hpp"


#include <SDL2/SDL.h>

Application::Application()
    : m_isRunning(true)
{
    m_currentPage = createGamePage();
    m_renderDevice = std::make_unique<RenderDevice>();
}

bool Application::init()
{

    if (m_window.init() == false)
    {
        return false;
    }

    m_renderDevice->init();
    return true;
}

void Application::destroy()
{
    m_renderDevice.reset();
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
    while (SDL_PollEvent(&m_event))
    {
        if (m_state[SDL_SCANCODE_ESCAPE] || m_event.type == SDL_QUIT)
        {
            m_isRunning = false;
        }
        // m_currentPage->onInput(m_event);
    }
    return true;
}

void Application::update(float dt)
{
    m_currentPage->update(dt);
}

void Application::render()
{
    m_currentPage->render(m_renderDevice);

    SDL_GL_SwapWindow(m_window.m_display);
}

Page* Application::createGamePage()
{
    return new GamePage();
}
