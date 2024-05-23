#pragma once

#include "GameObjects/Sprite.hpp"

#include <gl/glew.h>
#include <vector>

class Sprite;

class Player
{
public:
    std::vector<GLfloat> m_initialPosition{
        -0.5f, -0.5f, 0.0f // x, y, z
    };

    GLfloat spriteSize = 1.0f;

public:
    Sprite* m_sprite = nullptr;

    enum class directionState
    {
        Up,
        Down,
        Left,
        Right
    };

public:
    void changeState();
    void input();
    void update();
    std::vector<GLfloat> render();
    std::vector<GLfloat> getVertexSpecification();
    Sprite* createSprite();

public:
    Player(/* args */);
    ~Player();
};
