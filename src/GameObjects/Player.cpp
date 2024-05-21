#include "Player.hpp"

inline void Player::changeState()
{
}

void Player::input()
{
}

void Player::update()
{
}

void Player::render()
{
}

std::vector<GLfloat> Player::getVertexSpecification()
{
    return m_VertexData;
}

Sprite* Player::createSprite()
{
    return new Sprite();
}


Player::Player(/* args */)
{
}

Player::~Player()
{
}
