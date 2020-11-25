#ifndef	PHYSICSWORLDCOMPONENT_H
#define PHYSICSWORLDCOMPONENT_H
#include <reactphysics3d/reactphysics3d.h>
#include "IComponent.h"
namespace PFE
{

	class PhysicsWorldComponent : public IComponent
	{
	public:
		~PhysicsWorldComponent() { physicsCommon.destroyPhysicsWorld(world); }
		void start()  override;
	    void update(Time &timer) override;
	    void addProppertyFile() override;
	private:
		rp3d::PhysicsCommon physicsCommon;
		rp3d::PhysicsWorld* world;
	};

}

#endif 