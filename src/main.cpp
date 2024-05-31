#include "Application.hpp"
#include "SDL3/SDL_main.h"

int main(int argc, char* argv[])
{
    Application app;

    auto success = app.init();
    if (success)
    {
         app.run();
    }

    app.destroy();

    return EXIT_SUCCESS;
}