#include "rigidbodycomponent.h"

void PFE::RigidBodyComponent::start()
{
	body->setType(rp3d::BodyType::DYNAMIC);
	body->enableGravity(false);
	body->setMass(10);
}

void PFE::RigidBodyComponent::setBody(rp3d::RigidBody* body)
{
	this->body = body;
}

void PFE::RigidBodyComponent::addBoxShape(rp3d::BoxShape* boxShape)
{
	if (body != nullptr)
	{
		Collider *collider = body->addCollider(boxShape, rp3d::Transform::identity());
		colliders.push_back(collider);
	}
		
}

void PFE::RigidBodyComponent::addCapsuleShape(rp3d::CapsuleShape* capsuleShape)
{
	if (body != nullptr)
	{
		Collider* collider = body->addCollider(capsuleShape, rp3d::Transform::identity());
		colliders.push_back(collider);
	}

}

void PFE::RigidBodyComponent::update(Time& timer)
{
	rp3d::Transform currentTransform = body->getTransform();
	rp3d::Transform interpolateTransform = rp3d::Transform::interpolateTransforms(previusTransform, currentTransform, timer.getFactor());
	interpolarePosition = interpolateTransform.getPosition();
	previusTransform = currentTransform;
}

void PFE::RigidBodyComponent::addProppertyFile()
{
}

glm::vec3 PFE::RigidBodyComponent::getInterpolarePosition()
{
	return reactPhysicsVectorToGLMVector(interpolarePosition);
}
