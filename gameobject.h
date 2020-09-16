#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <map>
#include <iostream>
#include "renderobject.h"
#include "transform.h"
namespace PFE
{
    class GameObject
    {
        public:
            virtual void start() = 0;
            virtual void update() = 0;
            virtual ~GameObject(){destroy();}
            void addRenderObject(RenderObject *renderObject);
            void addChild(std::string name ,GameObject *object);
            GameObject *getChild(std::string name);
            void render();
            void setPosition(glm::vec3 position);
            void setSize(glm::vec3 size);
            void setRotate(float angle,glm::vec3 axis);
            glm::vec3 getSize();
            glm::vec3 getPosition();
            void destroy();
        private:
            Transform transform;
            bool isChildExist(std::string name);
            RenderObject *renderObject = 0;
            std::map<std::string,GameObject*>::iterator it;
            std::map<std::string,GameObject*>childrens;

    };
}


#endif // GAMEOBJECT_H
