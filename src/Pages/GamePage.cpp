#include "Pages/GamePage.hpp"
#include "GameObjects/Player.hpp"

#include "GamePage.hpp"

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
    m_player.update(dt);
}

void GamePage::render(RenderDevice* renderDevice)
{
    m_player.render(renderDevice);
}