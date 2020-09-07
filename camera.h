#ifndef CAMERA_H
#define CAMERA_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "keyboard.h"
#include "mouse.h"
//using namespace  reactphysics3d;
using namespace  std;
class Camera
{
public:
    Camera(float x,float y,float z,GLfloat sensitivity);
    void move();
    void setCurrentFrame();
    void mouse();
    glm::vec3 getPosition();
    void saveYaw();
    bool isBlocked = false;
    bool saveOnce = false;
    void setPosition(glm::vec3 pos);
    glm::mat4 getView();
    int getDirection();
    glm::vec3 getSize();
    bool isFrontClear = true;
    bool isBackClear = true;
    bool isLeftClear = true;
    bool isRightClear = true;
    bool isForwardMove;
    bool isBackwardMove;
    bool isLeftMove;
    bool isRihgtMove;
    glm::vec3 getFrontSizeLenght();
    glm::vec3 getRightSizeLenght();
    void collision(glm::vec3 objPos,glm::vec3 objSize);
private:
    bool isFirst =true;
    bool keys[1024];
    GLfloat camSpeed;
    void updateVectors();
    GLfloat speed;
    glm::vec3 collidersSize;
    glm::vec3 colliders[4];
    GLfloat collisionAngle;
    glm::vec3 size;
    glm::vec3 cameraPos;
    glm::vec3 cameraUp;
    glm::vec3 worldUp;
    glm::vec3 cameraRight;
    glm::vec3 cameraFront;
    glm::mat4 view;
    int dir;
    glm::vec3 temp;
    GLfloat mouseLastX,mouseLastY;
    GLfloat yaw,pitch,sensitivity;
    bool isFirstMouse  = true ;
};

#endif // CAMERA_H
