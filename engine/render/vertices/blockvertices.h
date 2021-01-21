#ifndef BLOCKVERTICES_H
#define BLOCKVERTICES_H
#include "IVertices.h"
/**
 * @brief The BlockVertices class Create and delete vertices for Block.
 * Extends abstract class IVertices.
 * Vertices using for creating shapes in render.
 */
namespace PFE
{
    class BlockVertices : public IVertices
    {
        public:
            GLfloat *getVertices()  override;
            void createVertices() override;
            void deleteVertices() override;
            int getArraySizeInBytes() override;
     
        private:
            GLfloat *vertices = 0;
            const int arraySize = 360;
      
    };
}


#endif // BLOCKVERTICES_H
