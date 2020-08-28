#include "animation2d.h"
void PFE::Animation2D::setTilesheet(TilesetTexture *texture, bool isAnimationVertical , int rowsCount,int columnsCount)
{
    this->texture = texture;
    this->rowsCount = rowsCount;
    this->columnCount  = columnsCount;
    this->isAnimationVertical = isAnimationVertical;
    animationStartPosition.x = 1;
    animationStartPosition.y = 1;
}
void PFE::Animation2D::setShader(Shader *shaderPrograms)
{
    texture->setShader(shaderPrograms);
}

void PFE::Animation2D::setStartTilesetCell(int rowCell,int columnCell)
{
        animationStartPosition.x = rowCell;
        animationStartPosition.y = columnCell;
}
void PFE::Animation2D::verticalAnimation()
{
    if(animationFrame > columnCount)
    {
        animationFrame = animationStartPosition.x;
    }
    texture->setTilePosition(rowsCount,columnCount,animationStartPosition.y,animationFrame);
}
void PFE::Animation2D::horizontalAnimation()
{
    if(animationFrame > rowsCount)
    {
        animationFrame = animationStartPosition.x;
    }
    texture->setTilePosition(rowsCount,columnCount,animationFrame,animationStartPosition.y);
}
void PFE::Animation2D::play(float speed)
{
    //if frames in tileset are from top to bottom
    if(isAnimationVertical)
    {
        verticalAnimation();
    }
    //if frames in tileset are from left to right
    else
    {
        horizontalAnimation();
    }
    if((glfwGetTime()/frameCounter)>=speed)
    {
        animationFrame++;
        frameCounter++;
    }
}
