#ifndef WALL_H
#define WALL_H

#include <engine/gameobject/gameobject.h>
namespace PFE
{
    class Wall : public GameObject
    {
        public:
            void start() override;
            void update(Time& timer) override;
            ~Wall() override{destroy();}
    };

}

#endif // WALL_H
