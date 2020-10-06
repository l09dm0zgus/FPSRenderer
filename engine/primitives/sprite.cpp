#include "sprite.h"
void PFE::Sprite::addTexture(string textureFile)
{
    tile = new TilesetTexture();
    tile->loadImageFile(textureFile);
    tile->create();
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
    Animation2D *anim = new Animation2D;
    anim->setTilesheet(tile,false,6,4);
    anim->setStartTilesetCell(1,1);
    animator.addAnimation(anim,"front");
    //animator.addAnimation(anim,"front");
}

void PFE::Sprite::render()
{
    tile->draw(0);
    shaderPrograms->use();

    animator.playAnimation("front",shaderPrograms,0.1);
    //animator.playAnimation("test",shaderPrograms,0.1);

    updatePerspective();
    buffers.drawVertices(6);
}

void PFE::Sprite::destroy()
{
    delete  shaderPrograms;
    shaderPrograms = nullptr;
   // delete  tile;
   // tile = nullptr;
    buffers.clear();
    vertices->deleteVertices();

}


