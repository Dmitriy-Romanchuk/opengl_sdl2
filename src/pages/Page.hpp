#pragma once

#include <string>

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
    virtual void onInput(/*const SDL_Event& input*/) = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;
};