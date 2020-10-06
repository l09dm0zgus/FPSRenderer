#ifndef VERTEXATRRIBUTE_H
#define VERTEXATRRIBUTE_H
#include<GL/glew.h>
#include <iostream>
using namespace std;
namespace PFE
{
    class VertexAtrribute
    {
        public:
            void create(int size,int mStride,int mId,int mPointer);
            int getStride();
            int getId();
            int getPointer();
        private:
            int stride = 0;
            int id = 0;
            int pointer = 0;
    };

}

#endif // VERTEXATRRIBUTE_H
