#include "pointlight.h"



float PFE::PointLight::getConstant()
{
    return constant;
}

void PFE::PointLight::setConstant(float constant)
{
    this->constant = constant;
}

float PFE::PointLight::getLinear()
{
    return linear;
}

void PFE::PointLight::setLinear(float linear)
{
    this->linear = linear;
}

float PFE::PointLight::getQuadratic()
{
    return quadratic;
}

void PFE::PointLight::setQuadratic(float quadratic)
{
    this->quadratic = quadratic;
}

