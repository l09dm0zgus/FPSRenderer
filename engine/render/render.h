#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include "window.h"
#include "engine/gameobject/scenecreator.h"
#include "engine/gameobject/gameobject.h"
#include "libs/ini.h"
using std::vector;
/**
 * @brief The Render class  Singleton class.We can have ONE object class.
 */
namespace PFE
{
    class Render
    {
        public:
            void load(string mapName);
            void render();
            void setCameraView(glm::mat4 view);
            void setViewportSize(glm::vec2 viewportSize);
            static Render& createRender();
            ~Render(){clear();};
        private:
            void clear();
            glm::vec2 viewportSize;
            glm::mat4 cameraView;
            Camera *player;
            Render(){};
            //Render& operator=(const Render&);
            Render(const Render&);
            SceneCreator sceneCreator;
            GameObject *scene;
    };
}


#endif // MAP_H
