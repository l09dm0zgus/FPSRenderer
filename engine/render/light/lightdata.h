#ifndef LIGHTDATA_H
#define LIGHTDATA_H
#include <sstream>
#include"scripts/lightsource.h"
#include"scripts/pointlight.h"
#include"scripts/spotlight.h"
#include"engine/render/shader/shader.h"
namespace PFE
{
	class LightData
	{
		private:
			std::vector<SpotLight*> spotLights;
			std::vector<PointLight*> pointLights;
			LightSource* directLight;
			void updateSpotLight(ShaderProgram* shaderProgram);
			void updateDirectLight(ShaderProgram* shaderProgram);
			void updatePointLight(ShaderProgram* shaderProgram);
		public:
			~LightData() {};
			void addDirectLight(LightSource* directLight);
			void addSpotLight(SpotLight* spotLight);
			void addPointLight(PointLight* pointLight);
			void updateLight(ShaderProgram* shaderProgram);
	};
}

#endif // LIGHTDATA_H