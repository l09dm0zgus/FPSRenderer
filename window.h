#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "keyboard.h"
using namespace  std;
namespace PFE
{
    class Window
    {
        public:
            Window(int w,int h,string windowTitle);
            void render(void (*renderCallback)(),void (*mouseCallback)(GLFWwindow*,double,double));
            void destroy();
            bool isFullscreen();
            void setFullscreen(bool fullscreen);
            static void resizeCallback(GLFWwindow *window ,int cx ,int cy);
        private:
             void GLFWInit();
             void GLEWInit();
             void setRenderOptions();
             GLFWwindow *window = nullptr;
             void init();
             int windowWidth,windowHeight;
             int viewportWidth,viewportHeight;
             int windowX,windowY;
             GLFWmonitor *monitor = nullptr;
             void resize(int cx , int cy);
             bool updateViewport = true;
             const char *windowTitle;
    };
}


#endif // WINDOW_H
