#include "Sprite.hpp"

#include "RenderDevice/RenderDevice.hpp"

void Sprite::render(RenderDevice* renderDevice, const glm::vec2& position, float scale)
{
    GLfloat data[5 * 4];

    data[0] = position.x;
    data[1] = position.y;
    data[2] = 0.0f;
    data[3] = 1.0f;
    data[4] = 1.0f;

    data[5] = position.x + scale;
    data[6] = position.y;
    data[7] = 0.0f;
    data[8] = 1.0f;
    data[9] = 0.0f;

    data[10] = position.x + scale;
    data[11] = position.y + scale;
    data[12] = 0.0f;
    data[13] = 0.0f;
    data[14] = 0.0f;

    data[15] = position.x;
    data[16] = position.y + scale;
    data[17] = 0.0f;
    data[18] = 0.0f;
    data[19] = 1.0f;

    auto size = sizeof(data);

    renderDevice->draw(data, size);

    // std::vector<GLfloat> vertexes{

    //     position[0], position[1], position[2],

    //     1.0f, 1.0f,

    //     position[0] + spriteSize, position[1], position[2],

    //     1.0f, 0.0f,

    //     position[0] + spriteSize, position[1] + spriteSize, position[2],

    //     0.0f, 0.0f,

    //     position[0], position[1] + spriteSize, position[2],

    //     0.0f, 1.0f
    // };
}
