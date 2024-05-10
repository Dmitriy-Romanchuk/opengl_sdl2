#include <SDL2/SDL.h>

class Window
{
private:
    int ScreenWidth = 800;
    int ScreenHeight = 800;
public:
    SDL_Window* Display;
    SDL_GLContext gOpenGLContext = nullptr;

public:
    Window();
    ~Window();
    bool InitSDL();
    bool InitGLEW();
    bool Render();
    void GetOpenGLVersionInfo();
};




