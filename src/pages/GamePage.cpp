#include "Pages/GamePage.hpp"

#include "iostream"

class Application;
class RenderDevice;

Page::Type GamePage::getPageType() const
{
    return Type();
}

void GamePage::onInput(const SDL_Event& m_event)
{
    m_player.input(m_event);
}

void GamePage::update(float dt)
{
}

void GamePage::render(const std::unique_ptr<RenderDevice>& m_renderDevice)
{
    m_renderDevice->draw(m_player.render());
}