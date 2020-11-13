#ifndef	PHYSICSWORLDCOMPONENT_H
#define PHYSICSWORLDCOMPONENT_H
#include <reactphysics3d/reactphysics3d.h>
#include "IComponent.h"
namespace PFE
{

	class PhysicsWorldComponent : public IComponent
	{
	public:
		~PhysicsWorldComponent() {}
		void start()  override;
	    void update() override;
	    void addProppertyFile() override;
		template<class T> T get(){ return data<T>; }
		template<class T> T inline static data=T(0);
	};

}

#endif 