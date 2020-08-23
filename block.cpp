#include "block.h"

Block::Block()
{
    SRT = glm::mat4(1.0f);
    rotate = glm::mat4(1.0f);
}
void Block::setPosition(glm::vec3 position)
{
    this->position = position;
    this->transform();
}

void Block::setRotate(GLfloat angle, glm::vec3 axis)
{
    rotate = glm::rotate(rotate,angle,axis);
    this->transform();
}
void Block::setSize(glm::vec3 size)
{
    this->size = size;
    this->transform();
}
void Block::setShaderFile(string vertexShader, string fragmentShader)
{
    shaders = new Shader(vertexShader.c_str(),fragmentShader.c_str());
}
void Block::loadTextures(string text1, string text2)
{

    tex1.loadImageFile(text1);
    tex2.loadImageFile(text2);
    tex1.create();
    tex2.create();
    //create vertices and buffers
    vertices.createVertices();
    blockBuffers.create(&vertices);


    //create arrtibutes for vertex
    blockBuffers.addAttribute(3,7);
    blockBuffers.addAttribute(2,7);
    blockBuffers.addAttribute(2,7);




}
glm::vec3 Block::getPosition()
{
    return this->position;
}
int a[2] = {0,1};
void Block::render(Camera &cam)
{

    shaders->use();

    shaders->setUniformVariable(a,2,"textures");
    tex1.draw(0);
    tex2.draw(1);

    glm::mat4 projection,view(1.0);
    view = cam.getView();
    //todo class window with persepctive

    projection = glm::perspective(glm::radians(65.0f),800.0f/600.0f,0.1f,100.0f);
    shaders->setUniformVariable(projection,"projection");
    shaders->setUniformVariable(view,"view");
    shaders->setUniformVariable(SRT,"model");
    shaders->setUniformVariable(size.x,"sizeX");
    shaders->setUniformVariable(size.z,"sizeY");

    blockBuffers.drawVertices(36);
}
void Block::transform()
{
    glm::mat4 scale(1.0),translate(1.0f);
    scale = glm::scale(scale,size);
    translate = glm::translate(translate,position);
    SRT=translate * rotate *scale;
}
void Block::destroy()
{
    delete  shaders;
    shaders = nullptr;
    blockBuffers.clear();
    vertices.deleteVertices();
}
glm::vec3 Block::getSize()
{
    return  this->size;
}

