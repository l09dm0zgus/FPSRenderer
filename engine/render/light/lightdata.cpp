#include "lightdata.h"

void PFE::LightData::updateSpotLight(ShaderProgram* shaderProgram)
{
	shaderProgram->setUniformVariable((int)spotLights.size(), "numberOfSpotLight");
	for (int i = 0; i < spotLights.size(); i++)
	{
		shaderProgram->setUniformVariable(spotLights[i]->getAmbient(), "spotLight[" + std::to_string(i) + "].ambient");
		shaderProgram->setUniformVariable(spotLights[i]->getDiffuse(), "spotLight[" + std::to_string(i) + "].diffuse");
		shaderProgram->setUniformVariable(spotLights[i]->getSpecular(), "spotLight[" + std::to_string(i) + "].specular");
		shaderProgram->setUniformVariable(glm::vec4(spotLights[i]->getPosition(), 0.0f), "spotLight[" + std::to_string(i) + "].position");
		shaderProgram->setUniformVariable(spotLights[i]->getDirection(), "spotLight[" + std::to_string(i) + "].direction");
		shaderProgram->setUniformVariable(spotLights[i]->getCutOff(), "spotLight[" + std::to_string(i) + "].cutOff");
		shaderProgram->setUniformVariable(spotLights[i]->getOuterCutOff(), "spotLight[" + std::to_string(i) + "].outerCutOff");
	}
}

void PFE::LightData::updateDirectLight(ShaderProgram* shaderProgram)
{
	if (directLight != nullptr)
	{
		shaderProgram->setUniformVariable(directLight->getAmbient(), "directionalLight.ambient");
		shaderProgram->setUniformVariable(directLight->getDiffuse(), "directionalLight.diffuse");
		shaderProgram->setUniformVariable(directLight->getSpecular(), "directionalLight.specular");
		shaderProgram->setUniformVariable(glm::vec4(directLight->getPosition(), 1.0f), "directionalLight.position");
	}
	else
	{
		std::cout << "ERROR::Failed creating light!!!" << std::endl;
		exit(-1);
	}
}

void PFE::LightData::updatePointLight(ShaderProgram* shaderProgram)
{
	shaderProgram->setUniformVariable((int)pointLights.size(), "numberOfPointLight");
	for (int i = 0; i < pointLights.size(); i++)
	{
		shaderProgram->setUniformVariable(pointLights[i]->getAmbient(), "pointLight[" + std::to_string(i) + "].ambient");
		shaderProgram->setUniformVariable(pointLights[i]->getDiffuse(), "pointLight[" + std::to_string(i) + "].diffuse");
		shaderProgram->setUniformVariable(pointLights[i]->getSpecular(), "pointLight[" + std::to_string(i) + "].specular");
		shaderProgram->setUniformVariable(glm::vec4(pointLights[i]->getPosition(), 0.0f), "pointLight[" + std::to_string(i) + "].position");
		shaderProgram->setUniformVariable(pointLights[i]->getConstant(), "pointLight[" + std::to_string(i) + "].constant");
		shaderProgram->setUniformVariable(pointLights[i]->getLinear(), "pointLight[" + std::to_string(i) + "].linear");
		shaderProgram->setUniformVariable(pointLights[i]->getQuadratic(), "pointLight[" + std::to_string(i) + "].quadratic");
	}
}

void PFE::LightData::addDirectLight(LightSource* directLight)
{
	this->directLight = directLight;
}

void PFE::LightData::addSpotLight(SpotLight* spotLight)
{
	if (spotLight != nullptr)
	{
		spotLights.push_back(spotLight);
	}
}

void PFE::LightData::addPointLight(PointLight* pointLight)
{
	if (pointLight != nullptr)
	{
		pointLights.push_back(pointLight);
	}
}

void PFE::LightData::updateLight(ShaderProgram* shaderProgram)
{
	updateDirectLight(shaderProgram);
	updatePointLight(shaderProgram);
	updateSpotLight(shaderProgram);
}
