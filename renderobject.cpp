#include "renderobject.h"
PFE::Transform PFE::RenderObject::getTransform()
{
    return  transform;
}
void PFE::RenderObject::setTransform(Transform &transform)
{
    this->transform = transform;
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
