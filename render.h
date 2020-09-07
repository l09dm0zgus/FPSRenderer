#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include "window.h"
//#include <reactphysics3d/reactphysics3d.h>
#include "block.h"
#include "sprite.h"
#include "camera.h"
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
            vector<RenderObject*> renderObjects;
            //vector<RenderObject*> s;
            void floor(int size,string texture);
            void ceiling(int size,string texture);
    };
}


#endif // MAP_H
