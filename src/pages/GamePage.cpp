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
    m_square.input();
    std::cout << "GAME PAGE" << std::endl;
}

void GamePage::update(float dt)
{
}

void GamePage::render(const std::unique_ptr<RenderDevice>& m_renderDevice)
{
    m_renderDevice->draw(m_square.render());
}