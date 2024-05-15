#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

class Camera
{
public:
    Camera();
public:
    glm::mat4 GetViewMatrix() const;
    glm::vec3 Position() const;

    void MouseLook(int mouseX, int mouseY);
    void MoveForvard(float speed);
    void MoveBackward(float speed);
    void MoveLeft(float speed);
    void MoveRight(float speed);


private:

    glm::vec3 mEye;
    glm::vec3 mViewDirection;
    glm::vec3 mUpVector;

    glm::vec2 mOldMousePosition;
};
