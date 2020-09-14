#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <map>
#include <iostream>
#include "renderobject.h"
namespace PFE
{
    class GameObject
    {
        public:
            virtual void start() = 0;
            virtual void update() = 0;
            void addRenderObject(RenderObject *renderObject);
            void addChild(std::string name ,GameObject *object);
            GameObject *getChild(std::string name);
            void render();
        private:
            bool isChildExist(std::string name);
            RenderObject *renderObject = 0;
            std::map<std::string,GameObject*>::iterator it;
            std::map<std::string,GameObject*>childrens;

    };
}


#endif // GAMEOBJECT_H
