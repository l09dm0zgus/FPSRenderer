#include "player.h"
#include <engine/components/physicsworldcomponent.h>

void PFE::Player::setCamera(Camera *camera)
{
    this->camera = camera;
}

void PFE::Player::start() {}

void PFE::Player::update(Time& timer)
{
    this->timer = &timer;
    deltaTime = timer.getDeltaTime();
    updatePhysics();
}

void PFE::Player::move(float speed, glm::vec3 direction)
{
    if (camera != nullptr)
    {
        transform.position += (speed * deltaTime * direction);
    }
}

void PFE::Player::updatePlayerPosition()
{
    CharacterCommand* action = inputHandler.handleInput();
    camera->rotateCamera(Mouse::getMousePosition());;
    if (action != nullptr)
    {
        action->execute(this);
    }
    view = camera->getView();
}

void PFE::Player::updatePhysics()
{
    RigidBodyComponent* rigidBody = dynamic_cast<RigidBodyComponent*>(getComponent("RigidBody"));
    PhysicsWorldComponent* physicsWorld = dynamic_cast<PhysicsWorldComponent*>(getComponent("PhysicsWorld"));
    if (physicsWorld != nullptr && rigidBody != nullptr)
    {
        CollisionEvent* event = physicsWorld->getCollisionEvent();
        float push = speed;
        if (event->isStay)
        {
            transform.position += ((-push - accumulatePush) * deltaTime * cameraDirection);
            accumulatePush +=100;
            event->isStay = false;
        }
        if (!event->isCollision && !event->isStay)
        {

            updatePlayerPosition();
            speed = 1000.0f;
        }
        //disable flying camera
        transform.position.y = 1;
        accumulatePush = 0;
        camera->updatePosition(transform.position);
        rigidBody->moveBody(transform.position);
        glm::vec3 rigidBodyPosition = rigidBody->getBodyPosition();
        setPosition(rigidBodyPosition);
    }
}

void PFE::Player::moveBackward()
{
    if(camera != nullptr)
    {
        cameraDirection = -1.0f * camera->getForwardVector();
        move(1000.0f,cameraDirection);
    }
}

void PFE::Player::moveForward()
{
    if(camera != nullptr)
    {
        cameraDirection = camera->getForwardVector();
        move(speed, cameraDirection);
    }
}

void PFE::Player::moveLeft()
{
    if(camera != nullptr)
    {
        cameraDirection = -1.0f * camera->getRightVector();
        move(speed,cameraDirection);
    }
}

void PFE::Player::moveRight()
{
    if(camera != nullptr)
    {
        cameraDirection = camera->getRightVector();
        move(speed,cameraDirection);
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
