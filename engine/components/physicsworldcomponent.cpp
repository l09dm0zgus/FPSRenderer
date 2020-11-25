#include "physicsworldcomponent.h"
void  PFE::PhysicsWorldComponent::start()
{
    rp3d::PhysicsWorld::WorldSettings settings;
    settings.defaultVelocitySolverNbIterations = 20;
    settings.isSleepingEnabled = true;
    settings.gravity = rp3d::Vector3(0, 9.81, 0);
    rp3d::PhysicsCommon physicsCommon;
    world = physicsCommon.createPhysicsWorld(settings);
    world->createRigidBody(reactphysics3d::Transform());
}
void PFE::PhysicsWorldComponent::update(Time& timer)
{
    if (world != nullptr)
    {
        timer.updatePhysicsWorld(world);
       // 
      
    }
    
}
void  PFE::PhysicsWorldComponent::addProppertyFile()
{

}