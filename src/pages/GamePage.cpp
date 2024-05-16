#include "GameObjects/Player.hpp"
#include "Pages/GamePage.hpp"


Page::Type GamePage::getPageType() const
{
    return Type();
}

void GamePage::onInput(/*const SDL_Event& input*/)
{
}

void GamePage::update(float dt)
{
}

void GamePage::render(const std::unique_ptr<RenderDevice>&m_renderDevice)
{
      m_renderDevice->draw(m_square.getVertexSpecification());
}