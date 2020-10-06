#ifndef MOUSE_H
#define MOUSE_H
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
namespace PFE
{
    class Mouse
    {
        public:
            static void mousePosCallback(GLFWwindow *window, double xpos, double ypos);
            static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mod);
            static glm::vec2 getMousePosition();
            static bool isMouseKeyPresses(int button);
        private:
            static bool buttons[32];
            static double x;
            static double y;
    };
}


#endif // MOUSE_H
