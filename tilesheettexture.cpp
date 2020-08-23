#include "tilesheettexture.h"
void PFE::TilesheetTexture::setShader(Shader *shader)
{
    this->shader = shader;
}
void PFE::TilesheetTexture::setTilePosition(float rows, float collums, float rowPos, float colPos)
{
    shader->setUniformVariable(rows,"rowsTile");
    shader->setUniformVariable(collums,"collumsTile");
    shader->setUniformVariable(rowPos,"rowPosition");
    shader->setUniformVariable(colPos,"collumsPosition");
}
