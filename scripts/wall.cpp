#include "wall.h"
#include "engine/components/physicsworldcomponent.h"
void PFE::Wall::start()
{
    cout<<"Wall created"<<endl;
    PhysicsWorldComponent c;
    c.start();

}

void PFE::Wall::update(Time& timer)
{

}
