#include "Pages/GamePage.hpp"

Page::Type GamePage::getPageType() const
{
    return Type();
}

void GamePage::onInput(const SDL_Event& m_event)
{
    m_platform.input(m_event);
}

void GamePage::update(float dt)
{
    m_platform.update(dt);
}

void GamePage::render(RenderDevice* renderDevice)
{
    m_platform.render(renderDevice);
}