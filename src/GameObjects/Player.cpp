#include "Player.hpp"

Player::Player()
{
    m_sprite = createSprite();
}

inline void Player::changeState()
{
}

void Player::input()
{
}

void Player::update()
{
}

std::vector<GLfloat> Player::render()
{
    return m_sprite->render(m_initialPosition, spriteSize);
}

Sprite* Player::createSprite()
{
    return new Sprite();
}

Player::~Player()
{
}
