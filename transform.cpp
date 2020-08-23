#include "transform.h"

PFE::Transform::Transform()
{
    SRT = glm::mat4(1.0f);
    rotate = glm::mat4(1.0f);
}
void PFE::Transform::updateMatrix()
{
    glm::mat4 scale(1.0),translate(1.0f);
    scale = glm::scale(scale,size);
    translate = glm::translate(translate,position);
    SRT=translate * rotate *scale;
}
void PFE::Transform::setPosition(glm::vec3 position)
{
    this->position = position;
    updateMatrix();
}

void PFE::Transform::setRotate(float angle, glm::vec3 axis)
{
    this->rotate = glm::rotate(rotate,angle,axis);
    updateMatrix();
}
void PFE::Transform::setSize(glm::vec3 size)
{
    this->size = size;
    updateMatrix();
}
glm::vec3 PFE::Transform::getSize()
{
    return size;
}
glm::vec3 PFE::Transform::getPosition()
{
    return position;
}
