#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event)
{
    float speed = 0.5f;
    // static int mouseX = gScreenWidth / 2;
    // static int mouseY = gScreenHeight / 2;

    const Uint8* state = SDL_GetKeyboardState(NULL);

    // if(Event->type == SDL_MOUSEMOTION)
    // {
    //     mouseX += Event->motion.xrel;
    //     mouseY += Event->motion.yrel;
    //     gCamera.MouseLook(mouseX, mouseY);
    // }

    if (state[SDL_SCANCODE_UP])
    {
        // g_uOffset += 0.01f;
        // std::cout << "g_uOffset: " << g_uOffset << std::endl;

        gCamera.MoveForvard(speed);
    }

    if (state[SDL_SCANCODE_DOWN])
    {
        // g_uOffset -= 0.01f;
        // std::cout << "g_uOffset: " << g_uOffset << std::endl;
        gCamera.MoveBackward(speed);
    }

    if (state[SDL_SCANCODE_LEFT])
    {
        // g_uRotate -= 1.0f;
        gCamera.MoveLeft(speed);
    }

    if (state[SDL_SCANCODE_RIGHT])
    {
        // g_uRotate += 1.0f;
        gCamera.MoveRight(speed);
    }

    if (state[SDL_SCANCODE_SPACE])
    {
        m_needRotate = false;
    }

    if (state[SDL_SCANCODE_RETURN])
    {
        m_needRotate = true;
    }
}
