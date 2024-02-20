#include "CApp.h"

void CApp::OnRender()
{
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, 800, 800);
    glClearColor(0.f, 1.f, 1.f, 1.f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if (m_needRotate == true)
    {
        g_uRotate -= 0.5f;
    }

    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    // glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, g_uOffset));
    //
    // model = glm::rotate(model, glm::radians(g_uRotate), glm::vec3(0.0f, 1.0f, 0.0f));
    // model = glm::scale(model, glm::vec3(g_uScale, g_uScale, g_uScale));
    //
    // GLint u_ModelMatrixLocation = glGetUniformLocation(gGraphicsPieplineShaderProgram, "u_ModelMatrix");
    //
    // glUniformMatrix4fv(u_ModelMatrixLocation, 1, GL_FALSE, &model[0][0]);

    // camera
    glm::mat4 view = gCamera.GetViewMatrix();
    GLint u_ViewLocation = glGetUniformLocation(gGraphicsPieplineShaderProgram, "u_ViewMatrix");

    glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, &view[0][0]);

    //////////////////////////////////////////////////////////////////////////

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)gScreenWidth / (float)gScreenHeight, 0.1f, 100.0f);

    GLint u_ProjectionLocation = glGetUniformLocation(gGraphicsPieplineShaderProgram, "u_Projection");

    glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, &perspective[0][0]);

    //////////////////////////////////////////////////////////////////////////

    glBindVertexArray(gVertexArrayObject);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); for wireframe render

    for (GLuint i = 0; i < 10; i++)

    {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), cubePositions[i]);

        model = glm::rotate(model, glm::radians(g_uRotate), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(g_uScale, g_uScale, g_uScale));

        GLint u_ModelMatrixLocation = glGetUniformLocation(gGraphicsPieplineShaderProgram, "u_ModelMatrix");

        glUniformMatrix4fv(u_ModelMatrixLocation, 1, GL_FALSE, &model[0][0]);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }

    SDL_GL_SwapWindow(Surf_Display);
}