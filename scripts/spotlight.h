#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#include "pointlight.h"
namespace PFE
{
	class SpotLight :public PointLight
	{
		private:
			glm::vec3 direction;
			float cutOff;
			float outerCutOff;
		public:
	
			glm::vec3 getDirection();
			void setDirection(glm::vec3 direction);
			float getCutOff();
			void setCutOff(float cutOff);
			float getOuterCutOff();
			void setOuterCutOff(float outerCutOff);

	}	;
}


#endif // SPOTLIGHT_H