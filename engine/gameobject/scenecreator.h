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
#include "scripts/lightsource.h"
#include "gameobject.h"
#include "engine/components/physicsworldcomponent.h"
#include "engine/components/rigidbodycomponent.h"
#include "engine/components/renderobjectcomponent.h"
#include "libs/vectorsconventers.h"
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
            LightSource *sceneLight;
            Camera* camera;
    };
}


#endif // SCENECREATOR_H
