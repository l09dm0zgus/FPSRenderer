#ifndef	PHYSICSWORLDCOMPONENT_H
#define PHYSICSWORLDCOMPONENT_H
#include <reactphysics3d/reactphysics3d.h>
#include "IComponent.h"
namespace PFE
{
	struct CollisionEvent
	{
		bool isCollision = false;
		bool isTrigger = false;
	};
	class PhysicsEventListener : public rp3d::EventListener
	{
		public:
			virtual void onContact(const CollisionCallback::CallbackData& callbackData) override;
			void setCollisionEvent(CollisionEvent* event);
		private:
			CollisionEvent* event;
			rp3d::Transform transform;
	};
	class PhysicsWorldComponent : public IComponent
	{
	public:
		~PhysicsWorldComponent() { physicsCommon.destroyPhysicsWorld(world); }
		PhysicsWorldComponent();
		void start()  override;
	    void update(Time &timer) override;
	    void addProppertyFile() override;
		rp3d::RigidBody* createRigidbody(rp3d::Vector3 position,rp3d::Quaternion quaternion);
		rp3d::CapsuleShape* createCapsuleShape(float radius, float height);
		rp3d::BoxShape* createBoxShape(rp3d::Vector3 halfExtends);
		CollisionEvent* getCollisionEvent();
	private:
		rp3d::PhysicsCommon physicsCommon;
		rp3d::PhysicsWorld* world;
		CollisionEvent* event;
		PhysicsEventListener listener;
	};

}

#endif 