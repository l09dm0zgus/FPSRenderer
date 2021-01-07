#include "tilesettexture.h"

void PFE::TilesetTexture::setShader(ShaderProgram *shader)
{
    try
    {
        if(!shader)
        {
            throw "Failed get shader program.";
        }
        this->shader = shader;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
        exit(-1);
    }
}

void PFE::TilesetTexture::setTilePosition(float rows, float collums, float rowPos, float colPos)
{
    try
    {
        if(!shader)
        {
            throw "Shader program does not exist.";
        }
        else
        {
            shader->setUniformVariable(rows,"rowsTile");
            shader->setUniformVariable(collums,"collumsTile");
            shader->setUniformVariable(rowPos,"rowPosition");
            shader->setUniformVariable(colPos,"collumsPosition");
        }
    }
    catch (const char* e)
    {
       std::cout<<e<<std::endl;
       exit(-1);
    }
}