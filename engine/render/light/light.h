#ifndef LIGHT_H
#define LIGHT_H
#include "engine/render/renderobject.h"
#include "engine/render/vertices/blockvertices.h"
namespace PFE 
{
	class Light : public RenderObject
	{
		private:
			glm::vec3 color;
		public:
			void render() override;
			void loadTextures() override;
			void destroy() override;
			void addTexture(string textureFile);
			glm::vec3 getColor();
			void setColor(glm::vec3 color);

	};
}

#endif // LIGHT_H
