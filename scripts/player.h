#ifndef PLAYER_H
#define PLAYER_H

#include <gameobject.h>
#include <camera.h>
namespace PFE
{
    class Player : public GameObject
    {
        public:
            void start() override;
            void update() override;
            void setCamera(Camera *camera);
        private:
            Camera *camera;
    };
}


#endif // PLAYER_H
