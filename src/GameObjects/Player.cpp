#include "Player.hpp"

Player::Player()
{
    m_sprite = createSprite();
}

inline void Player::changeState()
{
}

void Player::input(const Uint8* m_state)
{
        if(m_state[SDL_SCANCODE_UP])
        {
            m_startPosition[1] += 0.005;
        }

        if(m_state[SDL_SCANCODE_DOWN])
        {
            m_startPosition[1] -= 0.005;
        }

        if(m_state[SDL_SCANCODE_LEFT])
        {
            m_startPosition[0] -= 0.005;
        }

        if(m_state[SDL_SCANCODE_RIGHT])
        {
            m_startPosition[0] += 0.005;
        }

        if(m_state[SDL_SCANCODE_KP_MINUS])
        {
            spriteSize -= 0.005;
        }

        if(m_state[SDL_SCANCODE_KP_PLUS])
        {
            spriteSize += 0.005;
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
