#pragma once

#include "GameObjects/Player.hpp"
#include "Pages/Page.hpp"

class GamePage : public Page
{
public:
    Type getPageType() const;

    void onInput(const SDL_Event& m_event) override;
    void update(float dt) override;
    void render(const std::unique_ptr<RenderDevice>& m_renderDevice) override;

private:
    Player m_player;
};