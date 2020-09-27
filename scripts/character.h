#ifndef CHARACTER_H
#define CHARACTER_H
#include<glm/glm.hpp>
namespace PFE
{
    class Character
    {
        public:
            virtual ~Character(){};
            virtual void moveForward() = 0;
            virtual void moveBackward() = 0;
            virtual void moveLeft() = 0;
            virtual void moveRight() = 0;
        protected:
            virtual void move(float speed,glm::vec3 direction) = 0;
    };
    class CharacterCommand
    {
        public:
        virtual ~CharacterCommand(){};
        virtual void execute(Character *actor)  = 0;
    };
}


#endif // CHARACTER_H
