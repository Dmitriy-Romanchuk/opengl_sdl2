#include <SDL2/SDL.h>

class main_window
{
private:
    /* data */
public:
    SDL_Window* Surf_Display;
    SDL_GLContext gOpenGLContext = nullptr;

public:
    main_window(/* args */);
    ~main_window();
    bool Init();
    bool Render();
    void GetOpenGLVersionInfo();
};




