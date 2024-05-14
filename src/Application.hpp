// #include <Camera.h>
#include "MainWindow.hpp"
#include "RenderDevice/RenderDevice.hpp"
#include "pages/Page.hpp"

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <iostream>
#include <memory>
#include <string>

class Application
{
public:
    // NEED ACTUALIZE
    bool m_needRotate = false;
    GLuint m_shaderProgram = 0;
    GLuint m_lampShaderProgram = 0;
    GLuint vertexbuffer;
    float g_uOffset = -3.0f;
    float g_uRotate = 0.0f;
    float g_uScale = 0.5f;
    GLuint lightVAO = 0;
    GLuint texture;
    // Camera gCamera;

    // ACTUAL VARIABLES
    bool m_isRunning;
    Window window;
    SDL_Event event;

public:
    Application();

public:
    bool init();
    void run();
    void destroy();

private:
    bool proccessInput();
    void update(float dt);
    void render();

private:
    const Uint8* state = SDL_GetKeyboardState(NULL);
    Page* m_currentPage = nullptr;
    // std::unique_ptr<RenderDevice> m_renderDevice;

    /////////////////////////////////////////////////
private:
    void VertexSpecification();

    void CreateGraphicsPiepline();

    GLuint CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource);

    GLuint CompileShader(GLuint type, const std::string& source);

    std::string LoadShaderAsString(const std::string& filename);

    // GLuint gIndexBufferObject = 0;

    // void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();

    void OnCleanup();

    Page* createGamePage();
};
