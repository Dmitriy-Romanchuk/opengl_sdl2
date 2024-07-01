#include "Platform.hpp"

namespace
{
    struct
    {
        Platform::Direction direction;
        SDL_Keycode sym;
    } DirectionMapping[] = {
        { Platform::Direction::Left, SDLK_LEFT },
        { Platform::Direction::Right, SDLK_RIGHT },
    };

    Platform::Direction getDirection(SDL_Keycode sym)
    {
        for (const auto& mapping : DirectionMapping)
        {
            if (mapping.sym == sym)
            {
                return mapping.direction;
            }
        }
        assert(false);
        return Platform::Direction::None;
    }
} // namespace

Platform::Platform()
    : m_position({ -0.5f, -0.95f })
    , m_directionFlags(0u)
    , m_sprite(createSprite())
{
}

void Platform::input(const SDL_Event& m_event)
{
    auto sym = m_event.key.keysym.sym;

    switch (sym)
    {
    case SDLK_LEFT:
        addDirectionState(Direction::Left);
        removeDirectionState(Direction::Right);
        break;
    case SDLK_RIGHT:
        addDirectionState(Direction::Right);
        removeDirectionState(Direction::Left);
        break;
    default:
        break;
    }
}

void Platform::update(float dt)
{
    glm::vec2 offset = { 0.0f, 0.0f };

    if (m_directionFlags & static_cast<uint32_t>(Direction::Left))
    {
        offset.x = -m_speed * dt;
    }

    if (m_directionFlags & static_cast<uint32_t>(Direction::Right))
    {
        offset.x = +m_speed * dt;
    }

    m_position += offset;
}

void Platform::render(RenderDevice* renderDevice)
{
    m_sprite->render(renderDevice, m_position, m_scale);
}

void Platform::changeDirection(SDL_Keycode sym, bool add)
{
    Direction direction = getDirection(sym);

    if (add)
    {
        addDirectionState(direction);
    }
    else
    {
        removeDirectionState(direction);
    }
}

void Platform::addDirectionState(Direction direction)
{
    m_directionFlags |= static_cast<uint32_t>(direction);
}

void Platform::removeDirectionState(Direction direction)
{
    m_directionFlags &= ~static_cast<uint32_t>(direction);
}

Sprite* Platform::createSprite()
{
    return new Sprite();
}

Platform::~Platform()
{
}
