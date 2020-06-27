#ifndef AABBCOLLIDER_H
#define AABBCOLLIDER_H
#include "glm/glm.hpp"

class AABBCollider
{
public:
    AABBCollider(glm::vec3 pos,glm::vec3 size);
    ~AABBCollider();
    bool collision(glm::vec3 point ,glm::vec3 *newPoint);
private:
    glm::vec3 pos;
    glm::vec3 minBounds;
    glm::vec3 maxBounds;};

#endif // AABBCOLLIDER_H
