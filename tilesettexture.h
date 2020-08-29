#ifndef TILESHEETTEXTURE_H
#define TILESHEETTEXTURE_H
#include "texture.h"
namespace PFE
{
    class TilesetTexture :public Texture
    {
        public:
           ~TilesetTexture(){shader = nullptr;}
           void setShader(Shader *shader);
           void setTilePosition(float rows, float collums, float rowPos, float colPos);
        private:
           Shader *shader = nullptr;
    };
}


#endif // TILESHEETTEXTURE_H
