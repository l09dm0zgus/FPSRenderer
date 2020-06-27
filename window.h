#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace  std;
class Window
{
public:
    Window(int w,int h,string windowTitle);
    void render(void (*renderCallback)(),void (*mouseCallback)(GLFWwindow*,double,double),void (*keyCallback)(GLFWwindow*,int,int,int,int));
    void destroy();
private:
     GLFWwindow *window;
     void init();
     int w,h;
     const char *windowTitle;
};

#endif // WINDOW_H
