#ifndef RENDEROBJECTCOMPONENT_H
#define RENDEROBJECTCOMPONENT_H
#include <GL/glew.h>
#include "IComponent.h"
#include "engine/render/light/lightdata.h"
#include "engine/render/renderobject.h"
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
            Camera* camera;
        public:
            void start() override;
            void update(Time &timer) override;
            void addProppertyFile() override;
            void setLightData(LightData* lightData);
            void setCamera(Camera* camera);
            RenderObject* getRenderObject();
            void setRenderObject(RenderObject* renderObject);

};
}


#endif // RENDEROBJECTCOMPONENT_H
