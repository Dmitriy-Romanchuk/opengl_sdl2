#include "Pages/GamePage.hpp"
#include "GameObjects/Player.hpp"

#include "iostream"

class Application;
class RenderDevice;

Page::Type GamePage::getPageType() const
{
    return Type();
}

void GamePage::onInput(const Uint8* m_state)
{
    m_square.input(m_state);
    std::cout << "GAME PAGE" << std::endl;
}

void GamePage::update(float dt)
{
}

void GamePage::render(const std::unique_ptr<RenderDevice>& m_renderDevice)
{
    m_renderDevice->draw(m_square.render());
}