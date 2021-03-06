#include "player.h"
#include <engine/components/physicsworldcomponent.h>

void PFE::Player::setCamera(Camera *camera)
{
    this->camera = camera;
}

void PFE::Player::start() {}

void PFE::Player::update(Time& timer)
{
    deltaTime = timer.getDeltaTime();
    updatePhysics();
}

void PFE::Player::move(float speed, glm::vec3 direction)
{
    if(camera != nullptr)
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
        if (event->isCollision)
        {
            transform.position += 0;
        }
        if (event->isStay)
        {
            transform.position += (-100 * deltaTime * cameraDirection);
            //TODO add sleep function from Timer class
            for (int i = 0; i < 100; i++)
            {
                1 + 1;
            }
            event->isStay = false;
        }
        if (!event->isCollision && !event->isStay)
        {
            //TODO add sleep function from Timer class
            for (int i = 0; i < 20; i++)
            {
                1 + 1;
            }
            updatePlayerPosition();
        }
        //disable flying camera
        transform.position.y = 1;
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
        move(100.0f,cameraDirection);
    }
}

void PFE::Player::moveForward()
{
    if(camera != nullptr)
    {
        cameraDirection = camera->getForwardVector();
        move(100.0f,cameraDirection);
    }
}

void PFE::Player::moveLeft()
{
    if(camera != nullptr)
    {
        cameraDirection = -1.0f * camera->getRightVector();
        move(100.0f,cameraDirection);
    }
}

void PFE::Player::moveRight()
{
    if(camera != nullptr)
    {
        cameraDirection = camera->getRightVector();
        move(100.0f,cameraDirection);
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
