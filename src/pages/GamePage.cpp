#include "Pages/GamePage.hpp"
#include "GameObjects/Player.hpp"

#include "iostream"

class Application;
class RenderDevice;

Page::Type GamePage::getPageType() const
{
    return Type();
}

void GamePage::onInput(SDL_Event& m_event)
{
    // while (SDL_PollEvent(&m_event))
    // {
        //if (m_state[SDL_SCANCODE_UP])
        // {
           // m_uOffset += 0.01f;
           //std::cout << "UP " << std::endl;
        //}
    // }
}

void GamePage::update(float dt)
{
}

void GamePage::render(const std::unique_ptr<RenderDevice>& m_renderDevice)
{
    m_renderDevice->draw(m_square.render());
}