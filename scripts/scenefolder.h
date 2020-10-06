#ifndef SCENEFOLDER_H
#define SCENEFOLDER_H

#include <engine/gameobject/gameobject.h>
namespace PFE
{
    class SceneFolder : public GameObject
    {
        public:
            void start() override;
            void update() override;
            ~SceneFolder() override{destroy();}
    };
}


#endif // SCENEFOLDER_H
