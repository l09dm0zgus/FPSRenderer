#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "lightsource.h"
namespace PFE
{
	class PointLight:public LightSource
	{
		private:
			float constant;
			float linear;
			float quadratic;
		public:
			float getConstant();
			void setConstant(float constant);
			float getLinear();
			void setLinear(float linear);
			float getQuadratic();
			void setQuadratic(float quadratic);

	};
}


#endif // POINTLIGHT_H