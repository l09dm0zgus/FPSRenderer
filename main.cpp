#include <iostream>
#include "window.h"
#include "scene.h"
using namespace std;
Scene scene;
void mCallback(GLFWwindow *window,double xpos, double ypos);
void kCallback(GLFWwindow* window,int key,int scancode,int action,int mode);
int main()
{
    Window app(800,600,"Pure Fucking Armaggedon");
    app.setFullscreen(true);
    scene.start();
    app.render(scene.update,mCallback,kCallback);

    scene.clear();
    app.destroy();
    return 0;
}
void mCallback(GLFWwindow *window,double xpos, double ypos)
{
    scene.mouseCallback(window,xpos,ypos);
}
void kCallback(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    scene.keyboard(window,key,scancode,action,mode);
}
