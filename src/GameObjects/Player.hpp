#pragma once

#include "GameObjects/Sprite.hpp"

#include <gl/glew.h>
#include <vector>

class Sprite;

class Player
{
public:
    const std::vector<GLfloat> m_VertexData
    {
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, 0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f,  -0.5f, 0.0f,
    };

    std::vector<GLfloat> m_initialPosition 
    {
        -0.5f, -0.5f, 0.0f // x, y, z
    };

public:

    enum class directionState
    {   
        Up,
        Down,
        Left,
        Right
    };

Sprite* sprite;

public:
    void changeState();
    void input();
    void update();
    void render();
    std::vector<GLfloat> getVertexSpecification();

public:
    Player(/* args */);
    ~Player();
};




