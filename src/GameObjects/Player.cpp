#include "Player.hpp"

Player::Player()
{
    m_sprite = createSprite();
}

inline void Player::changeState()
{
}

void Player::input(const SDL_Event& m_event)
{
    if (m_event.type == SDL_EVENT_KEY_DOWN)
    {
        auto sym = m_event.key.keysym.sym;
        if (sym == SDLK_UP)
        {
            m_startPosition[1] += 0.005;
        }

        if (sym == SDLK_DOWN)
        {
            m_startPosition[1] -= 0.005;
        }

        if (sym == SDLK_LEFT)
        {
            m_startPosition[0] -= 0.005;
        }

        if (sym == SDLK_RIGHT)
        {
            m_startPosition[0] += 0.005;
        }

        if (sym == SDLK_KP_MINUS)
        {
            spriteSize -= 0.005;
        }

        if (sym == SDLK_KP_PLUS)
        {
            spriteSize += 0.005;
        }
    }
}

void Player::update()
{
}

std::vector<GLfloat> Player::render()
{
    return m_sprite->render(m_startPosition, spriteSize);
}

Sprite* Player::createSprite()
{
    return new Sprite();
}

Player::~Player()
{
}
