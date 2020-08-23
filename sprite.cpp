#include "sprite.h"

Sprite::Sprite()
{
    SRT = glm::mat4(1.0f);
    rotate = glm::mat4(1.0f);
}
void Sprite::setPosition(glm::vec3 position)
{
    this->position = position;
    transform();
}

void Sprite::setRotate(GLfloat angle, glm::vec3 axis)
{
    rotate = glm::rotate(rotate,angle,axis);
    transform();
}
void Sprite::setSize(glm::vec3 size)
{
    this->size = size;
    transform();
}
void Sprite::setShaderFile(string vertexShader, string fragmentShader)
{
    shaders = new Shader(vertexShader.c_str(),fragmentShader.c_str());
}

void Sprite::loadTextures(string text1)
{
    tex1.loadImageFile(text1);
    tex1.create();

    //create vertices and buffers
    vertices.createVertices();
    spriteBuffers.create(&vertices);


    vertices.createVertices();

    spriteBuffers.addAttribute(3,5);
    spriteBuffers.addAttribute(2,5);

    shaders->setUniformVariable(0,"image");


}
int frameCounter =1;
float framesPerSecond = 1.0f;
void Sprite::setTilePosition(float rows, float collums, float rowPos, float colPos)
{

    if(animationFrame >rows)
    {
        animationFrame = 1.0f;
    }
    framesPerSecond = 5.0f;
    tex1.setShader(shaders);
    tex1.setTilePosition(rows,collums,animationFrame,colPos);

    if((glfwGetTime()/frameCounter)>=0.1)
    {
        animationFrame++;
        frameCounter++;
    }

}
glm::vec3 Sprite::getPosition()
{
    return position;
}
void Sprite::render(Camera &cam)
{
    tex1.draw(0);
    shaders->use();

    setTilePosition(6.0f,4.0f,1.0f,1.0f);

    glm::mat4 projection,view(1.0);
    view = cam.getView();
    //todo class window with persepctive
    projection = glm::perspective(glm::radians(65.0f),800.0f/600.0f,0.1f,100.0f);
    shaders->setUniformVariable(projection,"projection");
    shaders->setUniformVariable(view,"view");
    shaders->setUniformVariable(SRT,"model");


    //animation();

    spriteBuffers.drawVertices(6);

}
void Sprite::transform()
{
    glm::mat4 scale(1.0),translate(1.0f);
    scale = glm::scale(scale,size);
    translate = glm::translate(translate,position);
    SRT=translate * rotate *scale;
}
void Sprite::destroy()
{
    delete  shaders;
    shaders = nullptr;
    spriteBuffers.clear();
    vertices.deleteVertices();
}
glm::vec3 Sprite::getSize()
{
    return  this->size;
}

