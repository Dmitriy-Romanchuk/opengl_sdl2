#pragma once

#include "GameObjects/Platform.hpp"
#include "Pages/Page.hpp"

class GamePage : public Page
{
public:
    Type getPageType() const;

    void onInput(const SDL_Event& m_event) override;
    void update(float dt) override;

    void render(RenderDevice* renderDevice) override;

private:
    Platform m_platform;
};