#pragma once

#include "Page.hpp"

class GamePage : public Page
{
public:
    Type getPageType() const;

    void onInput(const SDL_Event& input) override;
    void update(float dt) override;
    void render() override;
};