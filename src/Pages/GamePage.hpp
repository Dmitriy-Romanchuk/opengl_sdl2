#pragma once

#include "GameObjects/Player.hpp"
#include "Pages/Page.hpp"

class GamePage : public Page
{
public:
    Type getPageType() const;

    void onInput(const SDL_Event& m_event) override;
    void update(float dt) override;
    void render(RenderDevice* renderDevice) override;

private:
    Player m_player;
};