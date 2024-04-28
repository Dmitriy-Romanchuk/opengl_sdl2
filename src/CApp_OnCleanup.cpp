#include "application.h"
 
void Application::OnCleanup() 
{
    //SOIL_free_image_data(image);
    //glBindTexture(GL_TEXTURE_2D, 0);
    SDL_Quit();
}