#include <cstdint>


class Vertex;

class RenderDevice
{
public:
    RenderDevice();
    ~RenderDevice();

public:
    void init();
    void destroy();

    void draw(Vertex vertexBuffer[], uint32_t indexBuffer[]);

private:
    /* data */
};

RenderDevice::RenderDevice(/* args */)
{
}

RenderDevice::~RenderDevice()
{
}
