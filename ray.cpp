nclude "ray.h"

Ray::Ray()
{

}
void Ray::start(glm::vec3 startPos,int dir)
{
    if(rayLenght > 10 || rayLenght < -10 || isCollision)
    {
       rayLenght = 0;
    }
    else
    {
        switch (dir)
        {
            case 0:
                rayLenght++;
                endPos.x = startPos.x+rayLenght;
                endPos.y = startPos.y;
                endPos.z = startPos.z;
            break;
            case 1:
                rayLenght--;
                endPos.x = startPos.x+rayLenght;
                endPos.y = startPos.y;
                endPos.z = startPos.z;
            break;
            case 2:
                rayLenght++;
                endPos.x = startPos.x;
                endPos.y = startPos.y;
                endPos.z = startPos.z+rayLenght;
            break;
            case 3:
                rayLenght--;
                endPos.x = startPos.x;
                endPos.y = startPos.y;
                endPos.z = startPos.z+rayLenght;
            break;
        }

    }
    //std::cout<<"////////////////////////////////DEBUG////////////////////////////////////"<<std::endl;
    //std::cout<<dir<<" Lenght : "<<rayLenght<<std::endl;
    //std::cout<<dir<<" Pos : "<<endPos.x<<" "<<endPos.y<<" "<<endPos.z<<std::endl;
}
void Ray::setCollision(bool isCollision)
{
    this->isCollision = isCollision;
}
void Ray::checkCollision(glm::vec3 pos)
{

        if(endPos.x == pos.x && endPos.z == pos.z)
        {
           setCollision(true);
           cout<<" collision"<<endl;
        }
        else
        {
            setCollision(false);
        }
}
