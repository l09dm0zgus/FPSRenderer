#include "light.h"

void PFE::Light::render()
{
    shaderPrograms->use();
    shaderPrograms->setUniformVariable(color, "lightColor");
    updatePerspective();
    buffers.drawVertices(36);

}

void PFE::Light::loadTextures()
{
    //create vertices and buffers
    vertices = new BlockVertices();
    vertices->createVertices();
    buffers.create(vertices);

    //create arrtibutes for vertex
    buffers.addAttribute(3, 10);
    buffers.addAttribute(3, 10);
    buffers.addAttribute(2, 10);
    buffers.addAttribute(2, 10);
}

void PFE::Light::destroy()
{
    delete  shaderPrograms;
    shaderPrograms = nullptr;
    buffers.clear();
    vertices->deleteVertices();
}

void PFE::Light::addTexture(string textureFile)
{


}

glm::vec3 PFE::Light::getColor()
{
    return color;
}

void PFE::Light::setColor(glm::vec3 color)
{

    this->color = color;
}

