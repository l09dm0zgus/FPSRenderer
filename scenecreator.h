#ifndef SCENECREATOR_H
#define SCENECREATOR_H
#include "libs/ini.h"
#include "cube.h"
#include "sprite.h"
#include "scripts/wall.h"
#include "scripts/scenefolder.h"
#include "scripts/enemy.h"
#include "scripts/player.h"
namespace PFE
{
    class SceneCreator
    {
        public:
            void create(std::string mapName);
            GameObject *getSceneGraph();
        private:
            void ceiling(int size,std::string texture);
            void floor(int size,std::string texture);
            GameObject *scene;
    };
}


#endif // SCENECREATOR_H
