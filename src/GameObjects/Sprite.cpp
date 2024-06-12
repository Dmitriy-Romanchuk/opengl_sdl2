#include "Sprite.hpp"

#include "RenderDevice/RenderDevice.hpp"

void Sprite::render(RenderDevice* renderDevice, const glm::vec2& position, float scale)
{
    GLfloat data[4 * 4];

    data[0] = position.x;
    data[1] = position.y;
    data[2] = 1.0f;    //texture's coordinate
    data[3] = 1.0f;

    data[4] = position.x + scale;
    data[5] = position.y;
    data[6] = 1.0f;
    data[7] = 0.0f;

    data[8] = position.x + scale;
    data[9] = position.y + scale;
    data[10] = 0.0f;
    data[11] = 0.0f;

    data[12] = position.x;
    data[13] = position.y + scale;
    data[14] = 0.0f;
    data[15] = 1.0f;

    auto size = sizeof(data);

    renderDevice->draw(data, size);
}
