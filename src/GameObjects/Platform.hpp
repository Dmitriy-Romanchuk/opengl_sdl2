#pragma once

#include "GameObjects/Sprite.hpp"

#include <SDL2/SDL_events.h>
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <vector>

class Sprite;
class RenderDevice;

class Platform
{
public:
    Platform(/* args */);
    ~Platform();

public:
    enum class Direction
    {
        None,
        Up = 1 << 0,
        Down = 1 << 1,
        Left = 1 << 2,
        Right = 1 << 3
    };

public:
    void input(const SDL_Event& m_event);
    void update(float dt);
    void render(RenderDevice* renderDevice);

private:
    void changeDirection(SDL_Keycode sym, bool add);
    void addDirectionState(Direction direction);
    void removeDirectionState(Direction direction);
    Sprite* createSprite();

private:
    glm::vec2 m_position;
    float m_speed = 0.3f;
    uint32_t m_directionFlags;

    Sprite* m_sprite = nullptr;

    GLfloat m_scale = 0.15f;
};