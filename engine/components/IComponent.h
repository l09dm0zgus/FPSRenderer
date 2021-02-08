#ifndef ICOMPONENT_H
#define ICOMPONENT_H
#include <iostream>
#include "engine/time/time.h"
namespace PFE
{
    class IComponent
    {
        public:
            virtual ~IComponent(){}
            virtual void start() = 0;
            virtual void update(Time &timer) = 0;
            virtual void addProppertyFile() = 0;
 

            
    };
}

#endif // ICOMPONENT_H
