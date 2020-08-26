#include "sprite.h"
void PFE::Sprite::addTexture(string textureFile)
{
    tile.loadImageFile(textureFile);
    tile.create();
}

void PFE::Sprite::loadTextures()
{


    //create vertices and buffers
    vertices = new SpriteVertices();
    vertices->createVertices();
    buffers.create(vertices);


    //vertices.createVertices();

    buffers.addAttribute(3,5);
    buffers.addAttribute(2,5);

    shaderPrograms->setUniformVariable(0,"image");


}
int frameCounter =1;
float framesPerSecond;
void PFE::Sprite::setTilePosition(float rows, float collums, float rowPos, float colPos)
{

    if(animationFrame >rows)
    {
        animationFrame = 1.0f;
    }
    framesPerSecond = 90.0f;

    tile.setShader(shaderPrograms);
    tile.setTilePosition(rows,collums,animationFrame,colPos);
    if((glfwGetTime()/frameCounter)>=0.1)
    {
        animationFrame++;
        frameCounter++;
    }

}
void PFE::Sprite::render(Camera &cam)
{
    tile.draw(0);
    shaderPrograms->use();

    setTilePosition(6.0f,4.0f,1.0f,1.0f);

    glm::mat4 projection,view(1.0);
    view = cam.getView();
    //todo class window with persepctive
    projection = glm::perspective(glm::radians(65.0f),800.0f/600.0f,0.1f,100.0f);
    shaderPrograms->setUniformVariable(projection,"projection");
    shaderPrograms->setUniformVariable(view,"view");
    shaderPrograms->setUniformVariable(transform.getTransformMatrix(),"model");
    buffers.drawVertices(6);

}

void PFE::Sprite::destroy()
{
    delete  shaderPrograms;
    shaderPrograms = nullptr;
    buffers.clear();
    vertices->deleteVertices();

}


