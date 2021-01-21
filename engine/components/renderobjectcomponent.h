#ifndef RENDEROBJECTCOMPONENT_H
#define RENDEROBJECTCOMPONENT_H
#include <GL/glew.h>
#include "IComponent.h"
#include "scripts/lightsource.h"
#include "engine/camera/camera.h"
namespace PFE
{
    class RenderObjectComponent:public IComponent
    {
        /* TODO :
        Loading from xml file properties for RenderObject and create its.
        Properties for RenderObject -  primitive type(sprite,cube,mesh,etc),position,size,textures,shaders.
        Return pointer to object of class RenderObject.
        */
        private:
            RenderObject* renderObject;
            LightSource* lightSource;
            Camera* camera;
        public:
            void start() override;
            void update(Time &timer) override;
            void addProppertyFile() override;
            void setLightSource(LightSource* lightSource);
            void setCamera(Camera* camera);
            RenderObject* getRenderObject();
            void setRenderObject(RenderObject* renderObject);

};
}


#endif // RENDEROBJECTCOMPONENT_H
