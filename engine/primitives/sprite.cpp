#include "sprite.h"

void PFE::Sprite::addTexture(string textureFile)
{
    tile = new TilesetTexture();
    tile->loadImageFile(textureFile);
    tile->create();
    textures.push_back(tile);
    textureIds.push_back(textures.size() - 1);
}

void PFE::Sprite::loadTextures()
{
    //create vertices and buffers
    vertices = new SpriteVertices();
    vertices->createVertices();
    buffers.create(vertices);

    //create arrtibutes for vertex
    buffers.addAttribute(3,8);
    buffers.addAttribute(3,8);
    buffers.addAttribute(2,8);
    Animation2D *anim = new Animation2D;
    anim->setTilesheet(tile,false,6,4);
    anim->setStartTilesetCell(1,1);
    animator.addAnimation(anim,"front");
    //animator.addAnimation(anim,"front");
}

void PFE::Sprite::render()
{
    shaderPrograms->setUniformVariable(textureIds, "textures");
    shaderPrograms->setUniformVariable((int)textureIds.size(), "texturesCount");
    drawTextures();
    shaderPrograms->use();
    animator.playAnimation("front",shaderPrograms,0.1);
    updatePerspective();
    buffers.drawVertices(6);
}

void PFE::Sprite::destroy()
{
    delete  shaderPrograms;
    shaderPrograms = nullptr;
    buffers.clear();
    vertices->deleteVertices();
}
