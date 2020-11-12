#ifndef ICOMPONENT_H
#define ICOMPONENT_H
#include <iostream>
namespace PFE
{
    class IComponent
    {
        public:
            virtual ~IComponent(){}
            virtual void start() = 0;
            virtual void update() = 0;
            virtual void addProppertyFile() = 0;
            template<class T> T* get(){return *T}
        };
}

#endif // ICOMPONENT_H
