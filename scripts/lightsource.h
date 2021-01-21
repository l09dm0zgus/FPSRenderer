#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "engine/gameobject/gameobject.h"
#include "engine/render/light/light.h"
#include "engine/file/path.h"
namespace PFE
{
	class LightSource : public GameObject
	{
		private:
			Light* light;
		public:
			void start() override;
			void update(Time &timer) override;
			glm::vec3 getLightColor();
			glm::vec3 test;
	};
}

#endif // LIGHTSOURCE_H