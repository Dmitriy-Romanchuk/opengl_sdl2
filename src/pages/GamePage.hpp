#pragma once

#include "Pages/Page.hpp"
#include "GameObjects/Player.hpp"

class GamePage : public Page
{
public:
    Type getPageType() const;

    void onInput(const Uint8* m_state) override;
    void update(float dt) override;
    void render(const std::unique_ptr<RenderDevice>&m_renderDevice) override;

private:
    Player m_square;
};