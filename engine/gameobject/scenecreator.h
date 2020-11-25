#ifndef SCENECREATOR_H
#define SCENECREATOR_H
#include "libs/ini.h"
#include <glm/glm.hpp>
#include "engine/primitives/cube.h"
#include "engine/primitives/sprite.h"
#include "engine/file/path.h"
#include "scripts/wall.h"
#include "scripts/scenefolder.h"
#include "scripts/enemy.h"
#include "scripts/player.h"
#include "gameobject.h"
#include "engine/components/physicsworldcomponent.h"
namespace PFE
{
    class SceneCreator
    {
        public:
            void create(std::string mapName);
            GameObject *getSceneGraph();
            glm::mat4 getCameraView();
        private:
            void ceiling(int size,std::string texture);
            void floor(int size,std::string texture);
            GameObject *scene;
    };
}


#endif // SCENECREATOR_H
