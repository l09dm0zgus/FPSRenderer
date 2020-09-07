#include "camera.h"

Camera::Camera(float x,float y,float z,GLfloat sensitivity)
{
    this->cameraPos = glm::vec3(x,y,z);
    this->worldUp = glm::vec3(0.0f,1.0f,0.0f);
    this->view = glm::mat4(1.0f);
    this->mouseLastX = 400.0f;
    this->mouseLastY = 300.0f;
    this->yaw = 0.0f;
    this->pitch = 0.0f;
    this->sensitivity = sensitivity;
    this->updateVectors();
    this->size.x = 1.0;
    this->size.y = 1.0;
    this->size.z = 1.0;
    speed =10;


}

void Camera::move()
{

    camSpeed = 0.1;

    if(PFE::Keyboard::isKeyPressed(GLFW_KEY_W))
    {
        cout<<"W"<<endl;
        isForwardMove = true;
        isBackwardMove = false;

        if(this->isFrontClear)
        {
            this->cameraPos += camSpeed * this->cameraFront;
        }


    }
    else if(PFE::Keyboard::isKeyPressed(GLFW_KEY_S))
    {
        isForwardMove = false;
        isBackwardMove = true;

        if(this->isBackClear)
        {
            this->cameraPos -= camSpeed * this->cameraFront;
        }


    }
    else if(PFE::Keyboard::isKeyPressed(GLFW_KEY_A))
    {
        isLeftMove = true;
        isRihgtMove = false;

        if(this->isLeftClear)
        {
            this->cameraPos -= camSpeed * this->cameraRight;
        }

    }
    else if(PFE::Keyboard::isKeyPressed(GLFW_KEY_D))
    {
        isLeftMove = false;
        isRihgtMove = true;
        if(this->isRightClear)
        {
            this->cameraPos += camSpeed * this->cameraRight;
        }
    }


    else
    {
        isFrontClear = true;
        isBackClear = true;
        isLeftClear = true;
        isRightClear = true;

    }
    cameraPos.y = 1;


}

glm::mat4 Camera::getView()
{
    view =  glm::lookAt(cameraPos,cameraPos+cameraFront,cameraUp);
    return view;
}
int Camera::getDirection()
{
    return  this->dir;
}
void Camera::mouse()
{
    glm::vec2 mousePosition = PFE::Mouse::getMousePosition();
    if(this->isFirstMouse)
    {
        this->mouseLastX = mousePosition.x;
        this->mouseLastY = mousePosition.y;
        this->isFirstMouse = false;
    }
    GLfloat xoffset = mousePosition.x - this->mouseLastX;
    GLfloat yoffset = this->mouseLastY - mousePosition.y;
    this->mouseLastX = mousePosition.x;
    this->mouseLastY = mousePosition.y;

    xoffset *=this->sensitivity;
    yoffset *=this->sensitivity;
    this->yaw +=xoffset;
    this->pitch += yoffset;
    if(this->pitch>89.0f)
        this->pitch = 89.0f;
    if(this->pitch<-89.0f)
        this->pitch = -89.0f;
    this->updateVectors();
    // cout<<"Yaw :"<<yaw<<endl;

}
void Camera::updateVectors()
{
    glm::vec3 front(0,0,0);
    front.x = cos(glm::radians(this->yaw)) *  cos(glm::radians(this->pitch));
    front.y =  sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) *  cos(glm::radians(this->pitch));

    this->cameraFront = glm::normalize(front);
    this->cameraRight = glm::normalize(glm::cross(this->cameraFront, this->worldUp));
    this->cameraUp = glm::normalize(glm::cross(this->cameraRight, this->cameraFront));

}
glm::vec3 Camera::getSize()
{
    return this->size;
}
glm::vec3 Camera::getPosition()
{
    return  this->cameraPos;
}
void Camera::setPosition(glm::vec3 pos)
{
    this->cameraPos  = pos;
}
