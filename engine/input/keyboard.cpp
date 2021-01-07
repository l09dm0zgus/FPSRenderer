#include "keyboard.h"

bool PFE::Keyboard::keys[1024] = {0};

bool PFE::Keyboard::isKeyPressed(int key)
{
    return keys[key];
}

void PFE::Keyboard::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if(action  == GLFW_PRESS)
        keys[key]=true;
    else if(action == GLFW_RELEASE)
        keys[key]=false;
}
