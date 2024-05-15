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
    return window.Init();
}

void Application::destroy()
{
    m_renderDevice.reset();
    SDL_Quit();
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
        if (state[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT)
        {
            m_isRunning = false;
        }
        // m_currentPage->onInput(event);
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
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, 800, 800);
    glClearColor(0.1f, 0.5f, 0.1f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window.m_display);
}

Page* Application::createGamePage()
{
    return new GamePage();
}
