#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <glm/gtc/matrix_transform.hpp>
namespace PFE
{
    class Transform
    {
        public:
            Transform();
            void setPosition(glm::vec3 position);
            void setSize(glm::vec3 size);
            void setRotate(float angle,glm::vec3 axis);
            glm::mat4 getTransformMatrix();
            glm::vec3 getSize();
            glm::vec3 getPosition();
            glm::vec3 position;
        private:
            void updateMatrix();
            glm::mat4 transformMatrix;
            glm::vec3 size;
            glm::mat4 rotate;
    };

}

#endif // TRANSFORM_H
