#include "spotlight.h"

glm::vec3 PFE::SpotLight::getDirection()
{
    return direction;
}

void PFE::SpotLight::setDirection(glm::vec3 direction)
{
    this->direction = direction;
}

float PFE::SpotLight::getCutOff()
{
    return cutOff;
}

void PFE::SpotLight::setCutOff(float cutOff)
{
    this->cutOff = cutOff;
}

float PFE::SpotLight::getOuterCutOff()
{
    return outerCutOff;
}

void PFE::SpotLight::setOuterCutOff(float outerCutOff)
{
    this->outerCutOff = outerCutOff;
}

