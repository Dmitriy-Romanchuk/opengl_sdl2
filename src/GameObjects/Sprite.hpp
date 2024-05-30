#pragma once

#include <glm/vec2.hpp>

class RenderDevice;

class Sprite
{
public:
    void render(RenderDevice* renderDevice, const glm::vec2& position, float scale);
};