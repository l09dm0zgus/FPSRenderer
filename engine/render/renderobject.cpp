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
    shaderPrograms = new ShaderProgram(vertexShader.c_str(),fragmentShader.c_str());
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
    shaderPrograms->setUniformVariable(lightColor, "lightColor");
    shaderPrograms->setUniformVariable(lightPosition, "lightPosition");
    shaderPrograms->setUniformVariable(cameraPosition, "cameraPosition");
    
    
    
}

void PFE::RenderObject::setViewportProperties(glm::mat4 view, glm::vec2 viewportSize)
{
    this->viewMatrix = view;
    this->viewportSize = viewportSize;
}

void PFE::RenderObject::setLightColor(glm::vec3 lightColor)
{
    this->lightColor = lightColor;
}

void PFE::RenderObject::setCameraPosition(glm::vec3 cameraPosition)
{
    this->cameraPosition = cameraPosition;
}

void PFE::RenderObject::setLightPosition(glm::vec3 lightPosition)
{
    this->lightPosition = lightPosition;
}

