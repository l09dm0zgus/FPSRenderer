#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <map>
#include <iostream>
#include "engine/render/renderobject.h"
#include "engine/time/time.h"
#include "engine/transform/transform.h"
#include "engine/components/IComponent.h"
#include <reactphysics3d/reactphysics3d.h>
namespace PFE
{
    class GameObject
    {
        public:
            virtual void start() = 0;
            virtual void update(Time &timer) = 0;
            virtual ~GameObject(){destroy();}
            void load();
            void addComponent(std::string name,IComponent* component);
            IComponent *getComponent(std::string name);
            void addRenderObject(RenderObject *renderObject);
            void addChild(std::string name ,GameObject *object);
            GameObject *getChild(std::string name);
            void render(glm::mat4 view, glm::vec2 viewportSize, Time& timer);
            void setPosition(glm::vec3 position);
            void setSize(glm::vec3 size);
            void setRotate(float angle,glm::vec3 axis);
            glm::vec3 getSize();
            glm::vec3 getPosition();
            glm::mat4 getView();
            
            void destroy();
        protected:
             Transform transform;
             glm::mat4 view;
        private:
            void startComponents();
            void updateComponents(Time& timer);
            bool isChildExist(std::string name);
            bool isComponentExist(std::string);
            RenderObject *renderObject = 0;
            std::map<std::string,GameObject*>::iterator it;
            std::map<std::string,GameObject*>childrens;
            std::map<std::string,IComponent*>components;
            std::map<std::string,IComponent*>::iterator componentsIterator;
    };
}


#endif // GAMEOBJECT_H
