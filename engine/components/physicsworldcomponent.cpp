#include "physicsworldcomponent.h"
PFE::PhysicsWorldComponent::PhysicsWorldComponent()
{
    rp3d::PhysicsWorld::WorldSettings settings;
    settings.defaultVelocitySolverNbIterations = 20;
    settings.isSleepingEnabled = true;
    settings.gravity = rp3d::Vector3(0, -9.81, 0);
    world = physicsCommon.createPhysicsWorld(settings);
}
void  PFE::PhysicsWorldComponent::start()
{
    
}
void PFE::PhysicsWorldComponent::update(Time& timer)
{
    if (world != nullptr)
    {
        timer.updatePhysicsWorld(world);
    }
    
}
void  PFE::PhysicsWorldComponent::addProppertyFile()
{

}

rp3d::RigidBody* PFE::PhysicsWorldComponent::createRigidbody(rp3d::Vector3 position, rp3d::Quaternion quaternion)
{
    try
    {
        if(world != nullptr)
            return world->createRigidBody(rp3d::Transform(position, quaternion));
        else
            throw "Physics world not created!!!!";
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
        exit(-1);
    }
    
}

rp3d::CapsuleShape* PFE::PhysicsWorldComponent::createCapsuleShape(float radius, float height)
{
    return physicsCommon.createCapsuleShape(radius,height);
}

rp3d::BoxShape* PFE::PhysicsWorldComponent::createBoxShape(rp3d::Vector3 halfExtends)
{
    return physicsCommon.createBoxShape(halfExtends);
}
