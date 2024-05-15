#pragma once

#include <gl/gl.h>

class Player
{
private:
    GLfloat m_VertexData[9] =
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
    GLfloat* getVertexSpecification();

public:
    Player(/* args */);
    ~Player();
};




