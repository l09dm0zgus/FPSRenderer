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

void PFE::RenderObject::drawTextures()
{
    for(size_t i = 0;i<textures.size();i++)
    {
        textures[i]->draw(i);
    }
}
void PFE::RenderObject::updatePerspective()
{
    projectionMatrix = glm::perspective(glm::radians(65.0f),viewportSize.x/viewportSize.y,0.1f,100.0f);
    shaderPrograms->setUniformVariable(projectionMatrix,"projection");
    shaderPrograms->setUniformVariable(viewMatrix,"view");
    shaderPrograms->setUniformVariable(transform.getTransformMatrix(),"model");
}
void PFE::RenderObject::setViewportProperties(glm::mat4 view, glm::vec2 viewportSize)
{
    this->viewMatrix = view;
    this->viewportSize = viewportSize;
}
