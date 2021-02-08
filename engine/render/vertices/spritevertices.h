#ifndef SPRITEVERTICES_H
#define SPRITEVERTICES_H
#include "IVertices.h"
/**
 * @brief The SpriteVertices class Create and delete vertices for Sprite.
 * Extends abstract class IVertices.
 * Vertices using for creating shapes in render.
 */
namespace PFE
{
    class SpriteVertices : public IVertices
    {
        public:
            void createVertices() override;
            GLfloat *getVertices() override;
            void deleteVertices() override;
            int getArraySizeInBytes() override;
        private:
            GLfloat *vertices = 0;
            const int arraySize = 48;
    };

}

#endif // SPRITEVERTICES_H
