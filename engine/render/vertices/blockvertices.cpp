#include "blockvertices.h"

/**
 * @brief SpriteVertices::createVertices
 * Allocate memory for array with vertices.
 */
void PFE::BlockVertices::createVertices()
{
    // create array with vertices coordinates
    // first 3 colums is x ,y ,z coordinates for vertex position
    // second 2 colums is UV coordinates for first texture
    // third 2 colums is UV coordinates for second texture
    vertices = new GLfloat[arraySize]{
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,   0.0f, 1.0f
    };
}

/**
 * @brief SpriteVertices::getVertices
 * @return Pointer to begin array with vertices.
 */
GLfloat * PFE::BlockVertices::getVertices()
{
    if(vertices != nullptr)
    {
         return  vertices;
    }
    return 0;
}

/**
 * @brief SpriteVertices::deleteVertices
 * Delete array with vertices coordinates.
 */
void PFE::BlockVertices::deleteVertices()
{
    if(vertices != nullptr)
    {
        delete vertices;
        vertices = nullptr;
    }
}

/**
 * @brief SpriteVertices::getArraySizeInBytes
 *  Return array with vertices coordinates size in bytes.
 * @return Size.
 */
int PFE::BlockVertices::getArraySizeInBytes()
{
    return sizeof(float)*arraySize;
}
