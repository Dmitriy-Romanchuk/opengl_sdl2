#include "CApp.h"

void CApp::OnRender()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, 800, 800);
    glClearColor(0.f, 1.f, 1.f, 1.f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    

    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, g_uOffset));

    model = glm::rotate(model, glm::radians(g_uRotate), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(g_uScale, g_uScale, g_uScale));

    GLint u_ModelMatrixLocation = glGetUniformLocation(gGraphicsPieplineShaderProgram, "u_ModelMatrix");

    glUniformMatrix4fv(u_ModelMatrixLocation, 1, GL_FALSE, &model[0][0]);




    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)gScreenWidth/(float)gScreenHeight, 0.1f, 10.0f);

    GLint u_ProjectionLocation = glGetUniformLocation(gGraphicsPieplineShaderProgram, "u_Projection");

    glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, &perspective[0][0]);





    glBindVertexArray(gVertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(Surf_Display);
}