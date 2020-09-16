#include "player.h"

void PFE::Player::setCamera(Camera *camera)
{
    this->camera = camera;
}
void PFE::Player::start()
{

}
void PFE::Player::update()
{
    if(camera != nullptr)
    {
        camera->mouse();
        camera->move();
    }
}
