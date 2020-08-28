#ifndef ANIMATION2D_H
#define ANIMATION2D_H
#include "tilesettexture.h"
#include<GLFW/glfw3.h>
struct AnimationStartPosition
{
    int x;
    int y;
};

namespace PFE
{
    class Animation2D
    {
        public:
            void setTilesheet(TilesetTexture *texture,bool isAnimationVertical,int rowsCount,int columnsCount);
            void setShader(Shader *shaderPrograms);
            void setStartTilesetCell(int rowCell,int columnCell);
            void play(float speed);
        private:
            void verticalAnimation();
            void horizontalAnimation();
            float animationFrame = 1.0f;
            bool isAnimationVertical;
            AnimationStartPosition animationStartPosition;
            int frameCounter =1;
            TilesetTexture *texture;
            int rowsCount;
            int columnCount;
    };
}


#endif // ANIMATION2D_H
