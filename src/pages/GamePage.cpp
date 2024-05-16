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
    static int i = 0; //заглушка. инициализацю нужно вынести из рендера
    while(i < 1)
    {
        m_renderDevice->init(m_square.getVertexSpecification());
        ++i;
    }
    m_renderDevice->draw();

}