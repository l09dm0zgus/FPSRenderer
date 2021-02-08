#include "cube.h"

void PFE::Cube::addTexture(string textureFile)
{
    Texture *texture = new Texture();
    texture->loadImageFile(textureFile);
    texture->create();
    textures.push_back(texture);
    textureIds.push_back(textures.size()-1);
}

void PFE::Cube::loadTextures()
{
    //create vertices and buffers
    vertices = new BlockVertices();
    vertices->createVertices();
    buffers.create(vertices);

    //create arrtibutes for vertex
    buffers.addAttribute(3,10);
    buffers.addAttribute(3,10);
    buffers.addAttribute(2,10);
    buffers.addAttribute(2,10);
}

void PFE::Cube::render()
{
    shaderPrograms->use();
    shaderPrograms->setUniformVariable(textureIds,"textures");
    shaderPrograms->setUniformVariable((int)textureIds.size(), "texturesCount");
    drawTextures();
    updatePerspective();

    shaderPrograms->setUniformVariable(transform.getSize().x,"sizeX");
    shaderPrograms->setUniformVariable(transform.getSize().z,"sizeY");

    buffers.drawVertices(36);
}

void PFE::Cube::destroy()
{
    delete  shaderPrograms;
    shaderPrograms = nullptr;
    buffers.clear();
    vertices->deleteVertices();

    textures.clear();
}
