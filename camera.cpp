#include "camera.h"

PFE::Camera::Camera(float x,float y,float z,GLfloat sensitivity)
{
    position = glm::vec3(x,y,z);
    worldUp = glm::vec3(0.0f,1.0f,0.0f);
    view = glm::mat4(1.0f);
    mouseLastX = 400.0f;
    mouseLastY = 300.0f;
    yaw = 0.0f;
    pitch = 0.0f;
    this->sensitivity = sensitivity;
    position.y = 1;
    updateVectors();


}
void PFE::Camera::updatePosition(glm::vec3 position)
{
    this->position = position;
}
glm::vec3 PFE::Camera::getRightVector()
{
    updateVectors();
    return cameraRight;
}
glm::vec3 PFE::Camera::getForwardVector()
{
    updateVectors();
    return cameraFront;
}
glm::mat4 PFE::Camera::getView()
{
    view =  glm::lookAt(position,position+cameraFront,cameraUp);
    return view;
}
void PFE::Camera::rotateCamera(glm::vec2 mousePosition)
{
    if(isFirstMouse)
    {
        mouseLastX = mousePosition.x;
        mouseLastY = mousePosition.y;
        isFirstMouse = false;
    }
    GLfloat xoffset = mousePosition.x - mouseLastX;
    GLfloat yoffset = mouseLastY - mousePosition.y;
    mouseLastX = mousePosition.x;
    mouseLastY = mousePosition.y;

    xoffset *= sensitivity;
    yoffset *= sensitivity;
    yaw += xoffset;
    pitch += yoffset;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    updateVectors();
}
void PFE::Camera::updateVectors()
{
    glm::vec3 front(0,0,0);
    front.x = cos(glm::radians(yaw)) *  cos(glm::radians(pitch));
    front.y =  sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) *  cos(glm::radians(pitch));

    cameraFront = glm::normalize(front);
    cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
    cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));

}
