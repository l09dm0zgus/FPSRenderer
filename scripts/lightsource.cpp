#include "lightsource.h"

void PFE::LightSource::start()
{
	light = new Light();
	light->setColor(glm::vec3(0.78f, 0.05f, 0.84f));
	light->setShaderFile(Path::getShaderFilePath("LampVS.glsl"), Path::getShaderFilePath("LampFS.glsl"));
	light->loadTextures();
	addRenderObject(light);
	
}

void PFE::LightSource::update(Time& timer)
{
	
}

glm::vec3 PFE::LightSource::getLightColor()
{
	if (light != nullptr)
	{
		return light->getColor();
	}
}
