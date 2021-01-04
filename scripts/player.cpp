#include "player.h"
#include <engine/components/physicsworldcomponent.h>

void PFE::Player::setCamera(Camera *camera)
{
    this->camera = camera;
}
void PFE::Player::start()
{

}
void PFE::Player::update(Time& timer)
{
    deltaTime = timer.getDeltaTime();
    if(camera != nullptr)
    {
        CharacterCommand *action  = inputHandler.handleInput();
        camera->rotateCamera(Mouse::getMousePosition());;
        if(action != nullptr)
        {
            action->execute(this);
        }
        view = camera->getView();
        
    }

}

void PFE::Player::move(float speed, glm::vec3 direction)
{

    
    //disable flying camera
    transform.position.y = 1;
    if(camera != nullptr)
    {
        camera->updatePosition(transform.position);
        RigidBodyComponent* component = dynamic_cast<RigidBodyComponent*>(getComponent("RigidBody"));
        PhysicsWorldComponent* c = dynamic_cast<PhysicsWorldComponent*>(getComponent("PhysicsWorld"));
        if (component != nullptr && c != nullptr)
        {
            CollisionEvent* event = c->getCollisionEvent();
            if (event->isCollision)
                transform.position += 0;
            else
                transform.position += speed * deltaTime * direction;
            component->moveBody(transform.position);
            glm::vec3 pos = component->getBodyPosition();
            setPosition(pos);
            cout << "Physics Position X : " << pos.x << " Z : " << pos.z << endl;
            cout << "Player position X : " << transform.position.x << " Z : " << transform.position.z << endl;
            
        }
            
    }
}
void PFE::Player::moveBackward()
{
    if(camera != nullptr)
    {
        move(100.0f,(-camera->getForwardVector()));
    }
}
void PFE::Player::moveForward()
{
    if(camera != nullptr)
    {
        move(100.0f,camera->getForwardVector());
    }
}
void PFE::Player::moveLeft()
{
    if(camera != nullptr)
    {
        move(100.0f,(-camera->getRightVector()));
    }
}
void PFE::Player::moveRight()
{
    if(camera != nullptr)
    {
        move(100.0f,camera->getRightVector());
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
