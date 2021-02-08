#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include <glm/glm.hpp>
namespace PFE
{
	class LightSource
	{
		private:
			glm::vec3 ambient;
			glm::vec3 diffuse;
			glm::vec3 specular;
			glm::vec3 position;
		public:
			glm::vec3 getPosition();
			void setPosition(glm::vec3 position);
			glm::vec3 getAmbient();
			void setAmbient(glm::vec3 ambient);
			glm::vec3 getDiffuse();
			void setDiffuse(glm::vec3 diffuse);
			glm::vec3 getSpecular();
			void setSpecular(glm::vec3 specular);
};
}

#endif // LIGHTSOURCE_H