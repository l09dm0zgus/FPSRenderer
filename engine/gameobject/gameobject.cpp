#include "gameobject.h"
void PFE::GameObject::addComponent(std::string name, IComponent *component)
{

    try
    {
        if(isComponentExist(name))
            throw "Component with this name exist.";
        components[name] = component;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }

}
void PFE::GameObject::addChild(std::string name, GameObject* object)
{

    try
    {
        if (isChildExist(name))
            throw "Child with this name exist.";
        childrens[name] = object;
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }

}
void PFE::GameObject::destroy()
{


    for(it = childrens.begin();it != childrens.end();it++)
    {
        delete it->second;
        it->second = nullptr;
    }
    childrens.clear();
    for (componentsIterator = components.begin(); componentsIterator != components.end(); componentsIterator++)
    {
        delete componentsIterator->second;
        componentsIterator->second = nullptr;
    }
    components.clear();

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
PFE::IComponent* PFE::GameObject::getComponent(std::string name)
{
    try
    {
        if (isComponentExist(name))
            return components[name];
        else
            throw "Component not found.";
    }
    catch (const char* e)
    {
        return nullptr;
        std::cout << e << std::endl;
    }

}
bool PFE::GameObject::isChildExist(std::string name)
{
    it = childrens.find(name);
    return it != childrens.end();
}
bool PFE::GameObject::isComponentExist(std::string name)
{
    componentsIterator = components.find(name);
    return componentsIterator != components.end();
}
void PFE::GameObject::addRenderObject(RenderObject *renderObject)
{
    this->renderObject = renderObject;
    this->renderObject->setTransform(transform);
}
void PFE::GameObject::load()
{
    for(it = childrens.begin();it!=childrens.end();it++)
    {
        it->second->load();
    }
    start();
}
void PFE::GameObject::render(glm::mat4 view, glm::vec2 viewportSize)
{
    if(renderObject != nullptr)
    {
        renderObject->setViewportProperties(view,viewportSize);
        renderObject->render();
    }
    for(it = childrens.begin();it!=childrens.end();it++)
    {
        it->second->render(view,viewportSize);
    }
    update();
}
void PFE::GameObject::setPosition(glm::vec3 position)
{
    transform.setPosition(position);
    if(renderObject != nullptr)
    {
        renderObject->setTransform(transform);
    }
}
void PFE::GameObject::setSize(glm::vec3 size)
{
    transform.setSize(size);
    if(renderObject != nullptr)
    {
        renderObject->setTransform(transform);
    }
}
void PFE::GameObject::setRotate(float angle, glm::vec3 axis)
{
    transform.setRotate(angle,axis);
    if(renderObject != nullptr)
    {
        renderObject->setTransform(transform);
    }
}
glm::vec3 PFE::GameObject::getPosition()
{
    return transform.getPosition();
}
glm::vec3 PFE::GameObject::getSize()
{
    return transform.getSize();
}
glm::mat4 PFE::GameObject::getView()
{
    return view;
}
