#ifndef SCENE_H
#define SCENE_H
#include "camera.h"
#include "block.h"

class Scene
{
public:
    Scene();
    void start();
    static void update();
    void clear();
    void keyboard(GLFWwindow* window,int key,int scancode,int action,int mode);
    void mouseCallback(GLFWwindow *window,double xpos, double ypos);

};

#endif // SCENE_H
