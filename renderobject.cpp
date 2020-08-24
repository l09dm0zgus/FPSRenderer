#include "renderobject.h"
PFE::Transform PFE::RenderObject::getTransform()
{
    return  transform;
}
void PFE::RenderObject::setPosition(glm::vec3 position)
{
    transform.setPosition(position);
}
void PFE::RenderObject::setSize(glm::vec3 size)
{
    transform.setSize(size);
}
void PFE::RenderObject::setRotate(float angle, glm::vec3 axis)
{
    transform.setRotate(angle,axis);
}
glm::vec3 PFE::RenderObject::getPosition()
{
    return transform.getPosition();
}
glm::vec3 PFE::RenderObject::getSize()
{
    return transform.getSize();
}
void PFE::RenderObject::setShaderFile(string vertexShader, string fragmentShader)
{
    shaderPrograms = new Shader(vertexShader.c_str(),fragmentShader.c_str());
}
