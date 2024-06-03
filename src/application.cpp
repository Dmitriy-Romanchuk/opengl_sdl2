#include "Application.hpp"
#include "Pages/GamePage.hpp"

#include <SDL.h>
#include <iostream>

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
    SDL_Event event;
    auto eventCount = 0u;
    
    while (SDL_PollEvent(&event))
    {
        const auto type = event.type;

        if (type == SDL_QUIT)
        {
            m_isRunning = false;
        }
        else if(type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        {
            m_isRunning = false;    
        }
        else
        {
            m_currentPage->onInput(event);
        }

        eventCount++;
    }

    if (eventCount > 0)
    {
        std::cout << "eventCount = " << eventCount << std::endl;
    }

    return true;
}

void Application::update(float dt)
{
    m_currentPage->update(dt);
}

void Application::render()
{
    m_currentPage->render(m_renderDevice.get());

    SDL_GL_SwapWindow(m_window.m_display);
}

Page* Application::createGamePage()
{
    return new GamePage();
}
