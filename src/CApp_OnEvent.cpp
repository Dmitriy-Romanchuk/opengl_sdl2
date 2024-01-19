#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event)
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP])
    {
        g_uOffset += 0.01f;
        std::cout << "g_uOffset: " << g_uOffset << std::endl;
    }

    if (state[SDL_SCANCODE_DOWN])
    {
        g_uOffset -= 0.01f;
        std::cout << "g_uOffset: " << g_uOffset << std::endl;
    }

    if (state[SDL_SCANCODE_LEFT])
    {
        g_uRotate -= 1.0f;
    }

    if (state[SDL_SCANCODE_RIGHT])
    {
        g_uRotate += 1.0f;
    }
}
