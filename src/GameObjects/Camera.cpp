#include "Camera.hpp"

Camera::Camera()
{
    mEye = glm::vec3(0.0f, 0.8f, 0.0f);
    mViewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    mUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(mEye, mEye + mViewDirection, mUpVector);
}

glm::vec3 Camera::Position() const
{
    return mEye;
}

void Camera::MouseLook(int mouseX, int mouseY)
{
    static bool firstLook = true;
    glm::vec2 currentMouse = glm::vec2(mouseX, mouseY);
    if (firstLook)
    {
        mOldMousePosition = currentMouse;
        firstLook = false;
    }

    glm::vec2 mouseDelta = mOldMousePosition - currentMouse;

    mViewDirection = glm::rotate(mViewDirection, glm::radians(mouseDelta.x), mUpVector);
    mOldMousePosition = currentMouse;
}

void Camera::MoveForvard(float speed)
{
    mEye += (mViewDirection * speed);
}

void Camera::MoveBackward(float speed)
{
    mEye -= (mViewDirection * speed);
}

void Camera::MoveLeft(float speed)
{
    glm::vec3 rightVector = glm::cross(mViewDirection, mUpVector);
    mEye -= rightVector * speed;
}

void Camera::MoveRight(float speed)
{
    glm::vec3 rightVector = glm::cross(mViewDirection, mUpVector);
    mEye += rightVector * speed;
}
