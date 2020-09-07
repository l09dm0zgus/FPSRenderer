#include "mouse.h"
bool PFE::Mouse::buttons[32] = {0};

double PFE::Mouse::x = 0;

double PFE::Mouse::y = 0;

void PFE::Mouse::mouseButtonCallback(GLFWwindow *window, int button, int action, int mod)
{
    if(action  == GLFW_PRESS)
        buttons[button]=true;
    else if(action == GLFW_RELEASE)
        buttons[button]=false;
}
void PFE::Mouse::mousePosCallback(GLFWwindow *window, double xpos, double ypos)
{
    x = xpos;
    y = ypos;
}
glm::vec2 PFE::Mouse::getMousePosition()
{
    glm::vec2 position;
    position.x = x;
    position.y = y;
    return position;
}
bool PFE::Mouse::isMouseKeyPresses(int button)
{
    return buttons[button];
}
