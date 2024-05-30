#include "Application.hpp"

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