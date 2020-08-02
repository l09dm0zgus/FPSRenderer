#include "vertexatrribute.h"


void PFE::VertexAtrribute::create(int size,int mStride,int mId,int mPointer)
{

    cout<<"Id : "<<mId<<" Stride : "<<mStride<<" pointer: "<<mPointer<<endl;
    glVertexAttribPointer(mId,size,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*mStride,(GLvoid * )(sizeof (GLfloat)*mPointer));
    glEnableVertexAttribArray(mId);
    id =mId;
    stride  = mStride;
    id++;
    pointer = mPointer + size;

}
int PFE::VertexAtrribute::getId()
{
    return id;
}
int PFE::VertexAtrribute::getStride()
{
    return stride;
}
int PFE::VertexAtrribute::getPointer()
{
    return pointer;
}
