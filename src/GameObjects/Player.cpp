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
        // TODO Replace IF to Switch
        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_UP)
        {
            m_startPosition[1] += 0.005;
        }

        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_DOWN)
        {
            m_startPosition[1] -= 0.005;
        }

        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_LEFT)
        {
            m_startPosition[0] -= 0.005;
        }

        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_RIGHT)
        {
            m_startPosition[0] += 0.005;
        }

        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_KP_MINUS)
        {
            spriteSize -= 0.005;
        }

        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_KP_PLUS)
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
