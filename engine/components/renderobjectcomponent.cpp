#include "renderobjectcomponent.h"

PFE::RenderObject* PFE::RenderObjectComponent::getRenderObject()
{
    return renderObject;
}

void PFE::RenderObjectComponent::setRenderObject(RenderObject* renderObject)
{
    this->renderObject = renderObject;
}


void PFE::RenderObjectComponent::start()
{
}

void PFE::RenderObjectComponent::update(Time& timer)
{
   
    if (camera != nullptr)
    {
        renderObject->setCameraPosition(camera->getPosition());
    }
    
}

void PFE::RenderObjectComponent::addProppertyFile()
{
}

void PFE::RenderObjectComponent::setLightData(LightData* lightData)
{
    renderObject->setLightData(lightData);
}


void PFE::RenderObjectComponent::setCamera(Camera* camera)
{
    this->camera = camera;
}

