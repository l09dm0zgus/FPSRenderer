#include "gameobject.h"

void PFE::GameObject::addChild(std::string name, GameObject *object)
{

    try
    {
        if(isChildExist(name))
            throw "Child with this name exist.";
        childrens[name] = object;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }

}
PFE::GameObject *PFE::GameObject::getChild(std::string name)
{
    try
    {
        if(isChildExist(name))
            return childrens[name];
        else
            throw "Child not found.";
    }
    catch (const char*e)
    {
        return nullptr;
        std::cout<<e<<std::endl;
    }

}
bool PFE::GameObject::isChildExist(std::string name)
{
    it = childrens.find(name);
    return it != childrens.end();
}
void PFE::GameObject::addRenderObject(RenderObject *renderObject)
{
    this->renderObject = renderObject;
}
void PFE::GameObject::render()
{
    if(renderObject != nullptr)
    {
        renderObject->render();
    }
    for(it = childrens.begin();it!=childrens.end();it++)
    {
        it->second->render();
    }
    update();
}
