#include "rigidbodycomponent.h"

void PFE::RigidBodyComponent::start()
{
	if (isPlayer)
	{
		body->setType(rp3d::BodyType::DYNAMIC);
	}
	else
	{
		body->setType(rp3d::BodyType::STATIC);
	}
	body->enableGravity(false);
	body->setMass(10);
}

void PFE::RigidBodyComponent::setBody(rp3d::RigidBody* body)
{
	this->body = body;
}

void PFE::RigidBodyComponent::moveBody(glm::vec3 position)
{
	if (body != nullptr)
	{
		rp3d::Transform transform;
		transform.setPosition(glmVectorToReactPhysicsVector(position));
		transform.setOrientation(rp3d::Quaternion::identity());
		body->setTransform(transform);
	}
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

glm::vec3 PFE::RigidBodyComponent::getBodyPosition()
{
	return reactPhysicsVectorToGLMVector(body->getTransform().getPosition());;
}

void PFE::RigidBodyComponent::setIsPlayer(bool isPlayer)
{
	this->isPlayer = isPlayer;
}
