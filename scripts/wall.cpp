#include "wall.h"
#include "engine/components/physicsworldcomponent.h"
#include "engine/components/rigidbodycomponent.h"
#include "engine/components/IComponent.h"
void PFE::Wall::start()
{
    cout<<"Wall created"<<endl;
}

void PFE::Wall::update(Time& timer)
{
    RigidBodyComponent* component = dynamic_cast<RigidBodyComponent*>(getComponent("RigidBody"));
    if(component != nullptr)
        setPosition(component->getInterpolarePosition());
}
