#include "physicsworldcomponent.h"
void  PFE::PhysicsWorldComponent::start()
{
    rp3d::PhysicsWorld::WorldSettings settings;
    settings.defaultVelocitySolverNbIterations = 20;
    settings.isSleepingEnabled = true;
    settings.gravity = rp3d::Vector3(0, 9.81, 0);
    rp3d::PhysicsCommon physicsCommon;
    rp3d::PhysicsWorld* world = physicsCommon.createPhysicsWorld(settings);
    data<int> = 10;

    auto a = get<int>();
    std::cout << a <<std::endl;
}
void PFE::PhysicsWorldComponent::update()
{

}
void  PFE::PhysicsWorldComponent::addProppertyFile()
{

}