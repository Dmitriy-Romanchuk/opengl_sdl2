//#include "Application.hpp"
#include "MainWindow.hpp"

int main(int argc, char* argv[])
{
    Window window;
    window.InitGLEW();
    window.InitSDL();
    window.Render();
    window.GetOpenGLVersionInfo();

    //Application app;

    //auto success = app.init();
    //if (success)
    //{
    //    app.run();
    //}
    
    //app.destroy();

    return EXIT_SUCCESS;
}