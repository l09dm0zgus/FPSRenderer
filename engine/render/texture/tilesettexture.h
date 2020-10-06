#ifndef TILESHEETTEXTURE_H
#define TILESHEETTEXTURE_H
#include "texture.h"
namespace PFE
{
    class TilesetTexture :public Texture
    {
        public:
           ~TilesetTexture(){shader = nullptr;}
           void setShader(ShaderProgram *shader);
           void setTilePosition(float rows, float collums, float rowPos, float colPos);
        private:
           ShaderProgram *shader = nullptr;
    };
}


#endif // TILESHEETTEXTURE_H
