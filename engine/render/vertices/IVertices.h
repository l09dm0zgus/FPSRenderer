#ifndef IVERTICES_H
#define IVERTICES_H
#include <GL/glew.h>
/**
 * @brief The IVertices class Abstract class for SpriteVertices, BlockVertices.
 */
namespace PFE
{
    class IVertices
    {
        public:
            virtual GLfloat *getVertices()  = 0;
            virtual void createVertices() = 0;
            virtual void deleteVertices() = 0;
            virtual int getArraySizeInBytes()  = 0;
        };
}


#endif // IVERTICES_H
