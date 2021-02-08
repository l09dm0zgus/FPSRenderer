#include "lightsource.h"


glm::vec3 PFE::LightSource::getPosition()
{
    return position;
}

void PFE::LightSource::setPosition(glm::vec3 position)
{
    this->position = position;
}

glm::vec3 PFE::LightSource::getAmbient()
{
    return ambient;
}

void PFE::LightSource::setAmbient(glm::vec3 ambient)
{
    this->ambient = ambient;
}

glm::vec3 PFE::LightSource::getDiffuse()
{
    return diffuse;
}

void PFE::LightSource::setDiffuse(glm::vec3 diffuse)
{
    this->diffuse = diffuse;
}

glm::vec3 PFE::LightSource::getSpecular()
{
    return specular;
}

void PFE::LightSource::setSpecular(glm::vec3 specular)
{
    this->specular = specular;
}

