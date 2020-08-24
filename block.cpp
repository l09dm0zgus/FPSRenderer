#include "block.h"

void PFE::Block::addTexture(string textureFile)
{
    Texture texture;
    texture.loadImageFile(textureFile);
    texture.create();
    textures.push_back(texture);
    textureIds.push_back(textures.size()-1);
}

void PFE::Block::drawTextures()
{
    for(size_t i = 0;i<textures.size();i++)
    {
        textures[i].draw(i);
    }
}
void PFE::Block::loadTextures()
{

    //create vertices and buffers
    vertices = new BlockVertices();
    vertices->createVertices();
    buffers.create(vertices);

    //create arrtibutes for vertex
    buffers.addAttribute(3,7);
    buffers.addAttribute(2,7);
    buffers.addAttribute(2,7);
}
void PFE::Block::render(Camera &cam)
{

    shaderPrograms->use();
    shaderPrograms->setUniformVariable(textureIds,"textures");
    drawTextures();
    glm::mat4 projection,view(1.0);
    view = cam.getView();
    //todo class window with persepctive

    projection = glm::perspective(glm::radians(65.0f),800.0f/600.0f,0.1f,100.0f);
    shaderPrograms->setUniformVariable(projection,"projection");
    shaderPrograms->setUniformVariable(view,"view");
    shaderPrograms->setUniformVariable(transform.getTransformMatrix(),"model");
    shaderPrograms->setUniformVariable(transform.getSize().x,"sizeX");
    shaderPrograms->setUniformVariable(transform.getSize().z,"sizeY");

    buffers.drawVertices(36);
}
void PFE::Block::destroy()
{
    delete  shaderPrograms;
    shaderPrograms = nullptr;
    buffers.clear();
    vertices->deleteVertices();
}
