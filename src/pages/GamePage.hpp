#pragma once

#include "Pages/Page.hpp"

class Player;

class GamePage : public Page
{
public:
    Type getPageType() const;

    void onInput(/*const SDL_Event& input*/) override;
    void update(float dt) override;
    void render(const std::unique_ptr<RenderDevice>& m_renderDevice) override;

private:
    Player* m_square;
};