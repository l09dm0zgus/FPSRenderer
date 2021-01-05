#ifndef PLAYER_H
#define PLAYER_H
#include <engine/gameobject/gameobject.h>
#include <engine/camera/camera.h>
#include "engine/components/rigidbodycomponent.h"
#include "character.h"
namespace PFE
{
    class PlayerMoveForward:public CharacterCommand
    {
        public:
            virtual void execute(Character *actor)
            {
                actor->moveForward();
            }
    };
    class PlayerMoveBackward:public CharacterCommand
    {
        public:
            virtual void execute(Character *actor)
            {
                actor->moveBackward();
            }
    };
    class PlayerMoveLeft:public CharacterCommand
    {
        public:
            virtual void execute(Character *actor)
            {
                actor->moveLeft();
            }
    };
    class PlayerMoveRight:public CharacterCommand
    {
        public:
            virtual void execute(Character *actor)
            {
                actor->moveRight();
            }
    };
    class InputHandler
    {
        public:
            CharacterCommand *handleInput();
             InputHandler();
             ~InputHandler();
        private:
            CharacterCommand *moveForward;
            CharacterCommand *moveBackward;
            CharacterCommand *moveLeft;
            CharacterCommand *moveRight;
    };
    class Player : public GameObject,public Character
    {
        public:
            void start() override;
            void update(Time& timer) override;
            void setCamera(Camera *camera);
            void moveForward() override;
            void moveBackward() override;
            void moveLeft() override;
            void moveRight() override;
        private:
            void move(float speed,glm::vec3 direction) override;
            void updatePlayerPosition();
            void updatePhysics();
            glm::vec3 cameraDirection;
            int coll=0;
            float deltaTime = 0;
            Camera *camera;
            InputHandler inputHandler;

    };


}


#endif // PLAYER_H
