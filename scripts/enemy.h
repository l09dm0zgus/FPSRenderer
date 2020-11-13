#ifndef ENEMY_H
#define ENEMY_H

#include <engine/gameobject/gameobject.h>
#include "character.h"
namespace PFE
{
    class Enemy : public GameObject
    {
        public:
            void update(Time& timer) override;
            void start() override;
    };
}

#endif // ENEMY_H
