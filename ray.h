#ifndef RAY_H
#define RAY_H
#include <iostream>
#include "libs/glm/glm.hpp"
#include "libs/glm/gtc/matrix_transform.hpp"
using namespace  std;
class Ray
{
public:
    Ray();
    glm::vec4 endPos;
    void setCollision(bool isCollision);
    void start(glm::vec3 startPos,int dir);
    void checkCollision(glm::vec3 pos);
private:
    float rayLenght = 0;
    bool isCollision = false;
};

#endif // RAY_H
