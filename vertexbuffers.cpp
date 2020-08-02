#include "vertexbuffers.h"
void PFE::VertexBuffers::create(IVertices *vertices)
{
    glGenBuffers(1,&VBO);

    glGenVertexArrays(1,&VAO);

    //bind
    glBindVertexArray(VAO);

    vertices->createVertices();
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices->getArraySizeInBytes(),vertices->getVertices(),GL_STATIC_DRAW);

}
void PFE::VertexBuffers::addAttribute(int size,int attribStride)
{
    if(vertexAttributes.empty())
    {
        VertexAtrribute *attribute = new VertexAtrribute();
        attribute->create(size,attribStride,0,0);
        vertexAttributes.push_back(attribute);
    }
    else
    {
        VertexAtrribute *attribute = new VertexAtrribute();
        attribute->create(size , attribStride , lastAttribId , lastAttribPointer);
        vertexAttributes.push_back(attribute);
    }
    lastAttribId = vertexAttributes.back()->getId();
    lastAttribPointer = vertexAttributes.back()->getPointer();
}
void PFE::VertexBuffers::drawVertices(int count)
{

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,count);
    glBindVertexArray(0);
}
void PFE::VertexBuffers::clear()
{
    for(auto &attr:vertexAttributes)
    {
        delete attr;
        attr = nullptr;
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
