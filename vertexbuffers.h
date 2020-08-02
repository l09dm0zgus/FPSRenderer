#ifndef VERTEXBUFFERS_H
#define VERTEXBUFFERS_H
#include "IVertices.h"
#include "vertexatrribute.h"
#include <GL/glew.h>
#include <memory>
#include <vector>
namespace PFE
{
    class VertexBuffers
    {
        public:
            void create(IVertices *vertices);
            void drawVertices(int count);
            void addAttribute(int size,int attribStride);
            void clear();
        private:
            GLuint VBO,VAO;
            int lastAttribId = 0 , lastAttribPointer = 0;
            std::vector<VertexAtrribute*>vertexAttributes;

    };
}


#endif // VERTEXBUFFERS_H
