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

    //create arrtibutes for vertex
    buffers.addAttribute(3,5);
    buffers.addAttribute(2,5);
    shaderPrograms->setUniformVariable(0,"image");
    anim.setTilesheet(&tile,false,6,4);
    anim.setStartTilesetCell(1,1);
    animator.addAnimation(&anim,"front");

}

void PFE::Sprite::render(Camera &cam)
{
    tile.draw(0);
    shaderPrograms->use();
    animator.setShaderProgram(shaderPrograms);

    animator.playAnimation("front",0.1);
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


