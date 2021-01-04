#ifndef  RIGIDBODYCOMPONENT_H
#define  RIGIDBODYCOMPONENT_H
#include "IComponent.h"
#include <reactphysics3d/reactphysics3d.h>
#include "libs/vectorsconventers.h"
namespace PFE
{
	class RigidBodyComponent : public IComponent
	{
	public:
		void start() override;
		void setBody(rp3d::RigidBody* body);
		void moveBody(glm::vec3 position);
		void addBoxShape(rp3d::BoxShape* boxShape);
		void addCapsuleShape(rp3d::CapsuleShape* capsuleShape);
	    void update(Time& timer) override;
	    void addProppertyFile()  override;
		glm::vec3 getInterpolarePosition();
		glm::vec3 getBodyPosition();
		void setIsPlayer(bool isPlayer);

	private:
		rp3d::RigidBody* body;
		rp3d::Vector3 interpolarePosition;
		rp3d::Transform previusTransform;
		std::vector<rp3d::Collider*>colliders;
		bool isPlayer = false;
	};
}



#endif // ! RIGIDBODYCOMPONENT_H