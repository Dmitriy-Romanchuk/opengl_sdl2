#include "Sprite.hpp"

#include "RenderDevice/RenderDevice.hpp"

void Sprite::render(RenderDevice* renderDevice, const glm::vec2& position, float scale)
{
    GLfloat data[5 * 4];

    data[0] = position.x;
    data[1] = position.y;
    data[2] = 0.0f; //z
    data[3] = 0.0f; //coordinates of texture
    data[4] = 0.0f;

    data[5] = position.x + scale * 5;
    data[6] = position.y;
    data[7] = 0.0f;
    data[8] = 1.0f;
    data[9] = 0.0f;

    data[10] = position.x + scale * 5;
    data[11] = position.y + scale;
    data[12] = 0.0f;
    data[13] = 1.0f;
    data[14] = 1.0f;

    data[15] = position.x;
    data[16] = position.y + scale;
    data[17] = 0.0f;
    data[18] = 0.0f;
    data[19] = 1.0f;

    auto size = sizeof(data);

    renderDevice->draw(data, size);
}
