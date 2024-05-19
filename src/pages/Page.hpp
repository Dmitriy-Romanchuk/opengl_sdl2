#pragma once

#include "RenderDevice/RenderDevice.hpp"

#include <memory>
#include <SDL2/SDL.h>

class RenderDevice;

class Page
{
public:
    enum class Type
    {
        Game
    };

public:
    virtual ~Page(){};

public:
    virtual Type getPageType() const = 0;
    virtual bool isReadyToQuit()
    {
        return false;
    };

public:
    virtual void onInput(SDL_Event& input) = 0;
    virtual void update(float dt) = 0;
    virtual void render(const std::unique_ptr<RenderDevice>& m_renderDevice) = 0;
};