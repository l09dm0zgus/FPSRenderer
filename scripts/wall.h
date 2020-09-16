#ifndef WALL_H
#define WALL_H

#include <gameobject.h>
namespace PFE
{
    class Wall : public GameObject
    {
        public:
            void start() override;
            void update() override;
            ~Wall() override{destroy();}
    };

}

#endif // WALL_H
