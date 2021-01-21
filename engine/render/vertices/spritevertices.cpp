#include "spritevertices.h"
#include <iostream>

/**
 * @brief SpriteVertices::createVertices
 * Allocate memory for array with vertices.
 */
void PFE::SpriteVertices::createVertices()
{
    // create array with vertices
    // first 3 colums is x ,y ,z coordinates for vertex position
    // second 2 colums is UV coordinates for texture
    vertices = new GLfloat[arraySize]{
        0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f  ,0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f  ,1.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f  ,0.0f, 0.0f,

        0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f  ,0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f  ,1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f  ,1.0f, 0.0f
    };
}

/**
 * @brief SpriteVertices::deleteVertices
 * Delete array with vertices coordinates.
 */
void PFE::SpriteVertices::deleteVertices()
{
    //checks empty pointer
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
int PFE::SpriteVertices::getArraySizeInBytes()
{
    return sizeof(GLfloat[48]);
}

/**
 * @brief SpriteVertices::getVertices
 * @return Pointer to begin array with vertices.
 */
GLfloat *PFE::SpriteVertices::getVertices()
{
    if(vertices != nullptr)
    {
         return  vertices;
    }
    return 0;
}
