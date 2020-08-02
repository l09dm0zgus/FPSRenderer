#ifndef SCENE_H
#define SCENE_H
#include "camera.h"
#include "block.h"
#include "render.h"
class Scene
{
public:
    void start();
    static void update();
    void clear();
    void keyboard(GLFWwindow* window,int key,int scancode,int action,int mode);
    void mouseCallback(GLFWwindow *window,double xpos, double ypos);
private:

};

#endif // SCENE_H
