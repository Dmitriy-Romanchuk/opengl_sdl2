#pragma once

#include <string>
#include <format>

class Application;

class Page
{
public:
    enum class Type
    {
        Splash,
        Lobby,
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
    virtual void onInput(const std::string& input) = 0;
    virtual void update(float dt) = 0;
    virtual void render(std::string& buff) = 0;
};