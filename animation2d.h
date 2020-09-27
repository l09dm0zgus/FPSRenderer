#ifndef ANIMATION2D_H
#define ANIMATION2D_H
#include "tilesettexture.h"
#include <memory>
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
            ~Animation2D(){texture = nullptr;}
            void setTilesheet(TilesetTexture *texture,bool isAnimationVertical,int rowsCount,int columnsCount);
            void setShader(ShaderProgram *shaderPrograms);
            void setStartTilesetCell(int rowCell,int columnCell);
            void play(float speed);
            std::shared_ptr<int> ptr;
        private:
            void verticalAnimation();
            void horizontalAnimation();
            float animationFrame = 1.0f;
            bool isAnimationVertical;
            AnimationStartPosition animationStartPosition;
            int frameCounter =1;
            TilesetTexture *texture = nullptr;
            int rowsCount;
            int columnCount;
    };
}


#endif // ANIMATION2D_H
