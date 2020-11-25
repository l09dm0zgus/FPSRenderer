#include "player.h"

void PFE::Player::setCamera(Camera *camera)
{
    this->camera = camera;
}
void PFE::Player::start()
{

}
void PFE::Player::update(Time& timer)
{
    if(camera != nullptr)
    {
        CharacterCommand *action  = inputHandler.handleInput();
        camera->rotateCamera(Mouse::getMousePosition());;
        if(action != nullptr)
        {
            action->execute(this);
        }
        //disable flying camera
        transform.position.y = 1;
        view = camera->getView();
    }

}

void PFE::Player::move(float speed, glm::vec3 direction)
{
    transform.position += speed  * direction;
    if(camera != nullptr)
    {
        camera->updatePosition(transform.position);
    }
}
void PFE::Player::moveBackward()
{
    if(camera != nullptr)
    {
        move(0.1,(-camera->getForwardVector()));
    }
}
void PFE::Player::moveForward()
{
    if(camera != nullptr)
    {
        move(0.1,camera->getForwardVector());
    }
}
void PFE::Player::moveLeft()
{
    if(camera != nullptr)
    {
        move(0.1,(-camera->getRightVector()));
    }
}
void PFE::Player::moveRight()
{
    if(camera != nullptr)
    {
        move(0.1,camera->getRightVector());
    }
}
PFE::CharacterCommand *PFE::InputHandler::handleInput()
{
    if(PFE::Keyboard::isKeyPressed(GLFW_KEY_W)) return moveForward;
    if(PFE::Keyboard::isKeyPressed(GLFW_KEY_S)) return moveBackward;
    if(PFE::Keyboard::isKeyPressed(GLFW_KEY_D)) return moveRight;
    if(PFE::Keyboard::isKeyPressed(GLFW_KEY_A)) return moveLeft;

    return nullptr;
}
PFE::InputHandler::InputHandler()
{
    moveForward = new PlayerMoveForward();
    moveBackward = new PlayerMoveBackward();
    moveLeft = new PlayerMoveLeft();
    moveRight = new PlayerMoveRight();
}
PFE::InputHandler::~InputHandler()
{
    delete moveForward;
    delete moveBackward;
    delete moveLeft;
    delete moveRight;
    moveForward = nullptr;
    moveBackward = nullptr;
    moveLeft = nullptr;
    moveRight = nullptr;
}
