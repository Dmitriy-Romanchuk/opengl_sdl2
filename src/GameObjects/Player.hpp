#pragma once

#include <gl/glew.h>
#include <vector>

class Player
{
public:
    const std::vector<GLfloat> m_VertexData
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

public:

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
    void render();
    std::vector<GLfloat> getVertexSpecification();

public:
    Player(/* args */);
    ~Player();
};




