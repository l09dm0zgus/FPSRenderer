#ifndef RENDEROBJECTCOMPONENT_H
#define RENDEROBJECTCOMPONENT_H
#include "IComponent.h"
//#include "engine/render/renderobject.h"
namespace PFE
{
    class RenderObjectComponent:public IComponent
    {
        public:
            void start() override;
            void update(Time &timer) override;
    };
}


#endif // RENDEROBJECTCOMPONENT_H
