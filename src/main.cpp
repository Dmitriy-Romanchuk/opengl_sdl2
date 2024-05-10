#include "application.h"

// int main(int argc, char* argv[])
// {
//     Application theApp;

//     if (theApp.OnInit() == false)
//     {
//         return -1;
//     }

//     SDL_Event Event;

//     while (theApp.Running)
//     {
//         while (SDL_PollEvent(&Event))
//         {
//             theApp.OnEvent(&Event);
//         }

//         theApp.OnLoop();
//         theApp.OnRender();
//     }

//     theApp.OnCleanup();

//     return 0;
// }

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