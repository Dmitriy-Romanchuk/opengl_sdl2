#include "Player.hpp"

namespace
{
    struct
    {
        Player::Direction direction;
        SDL_Keycode sym;
    } DirectionMapping[] = {
        { Player::Direction::Up, SDLK_UP },
        { Player::Direction::Down, SDLK_DOWN },
        { Player::Direction::Left, SDLK_LEFT },
        { Player::Direction::Right, SDLK_RIGHT },
    };

    Player::Direction getDirection(SDL_Keycode sym)
    {
        for (const auto& mapping : DirectionMapping)
        {
            if (mapping.sym == sym)
            {
                return mapping.direction;
            }
        }
        assert(false);
        return Player::Direction::None;
    }
} // namespace

Player::Player()
    : m_position({ 0.0f, 0.0f })
    , m_directionFlags(0u)
    , m_sprite(createSprite())
{
}

void Player::input(const SDL_Event& m_event)
{
    if (m_event.type == SDL_KEYDOWN || m_event.type == SDL_KEYUP)
    {
        auto sym = m_event.key.keysym.sym;

        if (sym == SDLK_UP || sym == SDLK_DOWN || sym == SDLK_LEFT || sym == SDLK_RIGHT)
        {
            bool add = m_event.type == SDL_KEYDOWN ? true : false;
            changeDirection(sym, add);
        }
    }

    if (m_event.type == SDL_KEYDOWN)
    {
        auto sym = m_event.key.keysym.sym;

        if (sym == SDLK_KP_MINUS)
        {
            m_scale -= 0.005;
        }
        if (sym == SDLK_KP_PLUS)
        {
            m_scale += 0.005;
        }
    }
}

void Player::update(float dt)
{
    glm::vec2 offset = { 0.0f, 0.0f };

    if (m_directionFlags & static_cast<uint32_t>(Direction::Up))
    {
        offset.y = +m_speed * dt;
    }

    if (m_directionFlags & static_cast<uint32_t>(Direction::Down))
    {
        offset.y = -m_speed * dt;
    }

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

void Player::render(RenderDevice* renderDevice)
{
    m_sprite->render(renderDevice, m_position, m_scale);
}

void Player::changeDirection(SDL_Keycode sym, bool add)
{
    Direction direction = getDirection(sym);

    if (add == true)
    {
        addDirectionState(direction);
    }
    else
    {
        removeDirectionState(direction);
    }
}

void Player::addDirectionState(Direction direction)
{
    m_directionFlags |= static_cast<uint32_t>(direction);
}

void Player::removeDirectionState(Direction direction)
{
    m_directionFlags &= ~static_cast<uint32_t>(direction);
}

Sprite* Player::createSprite()
{
    return new Sprite();
}

Player::~Player()
{
}
