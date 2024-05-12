//#include <Camera.h>
#include "MainWindow.hpp"
#include "pages/Page.hpp"
#include "RenderDevice/RenderDevice.hpp"

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <iostream>
#include <string>
#include <memory>

class Application
{
public:
    bool m_isRunning;
    GLuint gVertexArrayObject = 0;
    GLuint gVertexBufferObject = 0;
    GLuint m_shaderProgram = 0;
    GLuint m_lampShaderProgram = 0;
    GLuint vertexbuffer;
    float g_uOffset = -3.0f;
    float g_uRotate = 0.0f;
    float g_uScale = 0.5f;
    //Camera gCamera;
    GLuint texture;
    GLuint lightVAO = 0;
    Window window;
    
    bool m_needRotate = false;

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
    Page* m_currentPage = nullptr;
    std::unique_ptr<RenderDevice> m_renderDevice;

/////////////////////////////////////////////////
private:
    void VertexSpecification();

    void CreateGraphicsPiepline();

    GLuint CreateShaderProgram(const std::string& vertexshadersource, const std::string& fragmentshadersource);

    GLuint CompileShader(GLuint type, const std::string& source);

    std::string LoadShaderAsString(const std::string& filename);

    //GLuint gIndexBufferObject = 0;

    //void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();

    void OnCleanup();

};
