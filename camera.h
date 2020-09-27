#ifndef CAMERA_H
#define CAMERA_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "keyboard.h"
#include "mouse.h"
namespace PFE
{
    class Camera
    {
        public:
            Camera(float x,float y,float z,GLfloat sensitivity);
            glm::mat4 getView();
            void updatePosition(glm::vec3 position);
            glm::vec3 getRightVector();
            glm::vec3 getForwardVector();
            void rotateCamera(glm::vec2 mousePosition);
        private:
            bool isFirst =true;
            void updateVectors();
            glm::vec3 position;
            glm::vec3 cameraUp;
            glm::vec3 worldUp;
            glm::vec3 cameraRight;
            glm::vec3 cameraFront;
            glm::mat4 view;
            GLfloat mouseLastX,mouseLastY;
            GLfloat yaw,pitch,sensitivity;
            bool isFirstMouse  = true ;
    };
}


#endif // CAMERA_H
