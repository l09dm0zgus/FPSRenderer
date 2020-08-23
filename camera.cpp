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

void Camera::move(GLFWwindow *window, int key, int scancode, int action, int mode,double &deltatime)
{

    camSpeed = speed *deltatime;
    if(action  == GLFW_PRESS)
        this->keys[key]=true;
    else if(action == GLFW_RELEASE)
        this->keys[key]=false;

        if(this->keys[GLFW_KEY_W])
        {
            isForwardMove = true;
            isBackwardMove = false;

            if(this->isFrontClear)
            {
                this->cameraPos += camSpeed * this->cameraFront;
            }


        }
        else if(this->keys[GLFW_KEY_S])
        {
            isForwardMove = false;
            isBackwardMove = true;

            if(this->isBackClear)
            {
                this->cameraPos -= camSpeed * this->cameraFront;
            }


        }
        else if(this->keys[GLFW_KEY_A])
        {
            isLeftMove = true;
            isRihgtMove = false;
            cout<<"Left :"<<isLeftMove<<endl;
            if(this->isLeftClear)
            {
                this->cameraPos -= camSpeed * this->cameraRight;
            }

        }
        else if(this->keys[GLFW_KEY_D] )
        {
            isLeftMove = false;
            isRihgtMove = true;
            cout<<"Right :"<<isRihgtMove<<endl;
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
void Camera::mouse(GLFWwindow *window, double xpos, double ypos)
{
     if(this->isFirstMouse)
     {
         this->mouseLastX = xpos;
         this->mouseLastY = ypos;
         this->isFirstMouse = false;
     }
     GLfloat xoffset = xpos - this->mouseLastX;
     GLfloat yoffset = this->mouseLastY - ypos;
     this->mouseLastX = xpos;
     this->mouseLastY = ypos;

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
