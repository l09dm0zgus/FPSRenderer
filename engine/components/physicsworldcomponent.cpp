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
    if (world != nullptr)
    {
        event = new CollisionEvent();
        listener.setCollisionEvent(event);
        world->setEventListener(&listener);
    }
}

void PFE::PhysicsWorldComponent::update(Time& timer)
{
    if (world != nullptr)
    {
        timer.updatePhysicsWorld(world);
    }
}

void  PFE::PhysicsWorldComponent::addProppertyFile() {}

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

PFE::CollisionEvent* PFE::PhysicsWorldComponent::getCollisionEvent()
{
    return this->event;
}

void PFE::PhysicsEventListener::onContact(const CollisionCallback::CallbackData& callbackData)
{
    for (rp3d::uint p = 0; p < callbackData.getNbContactPairs(); p++)
    {
        ContactPair contactPair = callbackData.getContactPair(p);
        if(contactPair.getEventType() == ContactPair::EventType::ContactStart)
        {
            event->isCollision = true;
            event->isStay = false;
        }
        if(contactPair.getEventType() == ContactPair::EventType::ContactStay)
        {
            event->isCollision = false;
            event->isStay = true;
        }
        if(contactPair.getEventType() == ContactPair::EventType::ContactExit)
        {
            event->isCollision = false;
            event->isStay = false;
        }
    }
}

void PFE::PhysicsEventListener::setCollisionEvent(CollisionEvent* event)
{
    this->event = event;
}
