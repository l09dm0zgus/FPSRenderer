#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "GLFW/glfw3.h"
namespace PFE
{
    class Keyboard
    {
        public:
            static void keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
            static bool isKeyPressed(int key);
        private:
            static bool keys[1024];
    };

}

#endif // KEYBOARD_H
