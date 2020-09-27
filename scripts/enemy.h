#ifndef ENEMY_H
#define ENEMY_H

#include <gameobject.h>
#include "character.h"
namespace PFE
{
    class Enemy : public GameObject
    {
        public:
            void update() override;
            void start() override;
    };
}

#endif // ENEMY_H