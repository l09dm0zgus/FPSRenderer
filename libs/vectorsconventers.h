#ifndef VECTORSCONVENTERS_H
#define VECTORSCONVENTERS_H
#include <glm/glm.hpp>
#include <reactphysics3d/reactphysics3d.h>
using namespace reactphysics3d;
using namespace glm;
inline vec3  reactPhysicsVectorToGLMVector(Vector3 vector)
{
    vec3 result;
    result.x = vector.x;
    result.y = vector.y;
    result.z = vector.z;
    return result;
}
inline Vector3 glmVectorToReactPhysicsVector(vec3 vector)
{
    Vector3 result;
    result.x = vector.x;
    result.y = vector.y;
    result.z = vector.z;
    return result;
}
#endif // VECTORSCONVENTERS_H
