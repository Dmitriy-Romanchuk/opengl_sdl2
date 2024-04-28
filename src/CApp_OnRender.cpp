#include "application.h"

void Application::OnRender()
{
    glUseProgram(m_shaderProgram);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, 800, 800);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if (m_needRotate == true)
    {
        g_uRotate -= 0.5f;
    }
    glm::vec3 objectColor = { 1.0f, 0.5f, 0.31f };
    glm::vec3 lightColor = { 1.0f, 1.0f, 1.0f };
    glm::vec3 lightPos = { 0.3f, 0.9f, -2.0f };

    GLint objectColorLoc = glGetUniformLocation(m_shaderProgram, "objectColor");
    GLint lightColorLoc = glGetUniformLocation(m_shaderProgram, "lightColor");
    GLint lightPosLoc = glGetUniformLocation(m_shaderProgram, "lightPos");
    GLint viewPosLoc = glGetUniformLocation(m_shaderProgram, "viewPos");

    glUniform3f(objectColorLoc, objectColor.r, objectColor.g, objectColor.b);
    glUniform3f(lightColorLoc, lightColor.r, lightColor.g, lightColor.b);
    glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
    glUniform3f(viewPosLoc, gCamera.Position().x, gCamera.Position().y, gCamera.Position().z);

    glm::mat4 view = gCamera.GetViewMatrix();
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, g_uOffset));
    model = glm::rotate(model, glm::radians(g_uRotate), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(g_uScale, g_uScale, g_uScale));

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)gScreenWidth / (float)gScreenHeight, 0.1f, 10.0f);

    GLint u_ModelMatrixLocation = glGetUniformLocation(m_shaderProgram, "u_ModelMatrix");
    GLint u_ViewLocation = glGetUniformLocation(m_shaderProgram, "u_ViewMatrix");
    GLint u_ProjectionLocation = glGetUniformLocation(m_shaderProgram, "u_Projection");

    glUniformMatrix4fv(u_ModelMatrixLocation, 1, GL_FALSE, &model[0][0]);
    glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, &perspective[0][0]);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //for wireframe render

    glBindVertexArray(gVertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    //--------------------------------------------------------------------------------
    // drawing the small light cube
    glUseProgram(m_lampShaderProgram);

    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));

    u_ModelMatrixLocation = glGetUniformLocation(m_lampShaderProgram, "u_ModelMatrix");
    u_ViewLocation = glGetUniformLocation(m_lampShaderProgram, "u_ViewMatrix");
    u_ProjectionLocation = glGetUniformLocation(m_lampShaderProgram, "u_Projection");

    glUniformMatrix4fv(u_ViewLocation, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(u_ProjectionLocation, 1, GL_FALSE, &perspective[0][0]);
    glUniformMatrix4fv(u_ModelMatrixLocation, 1, GL_FALSE, &model[0][0]);

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    SDL_GL_SwapWindow(Surf_Display);
}