#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include <reactphysics3d/reactphysics3d.h>
#include "block.h"
#include "sprite.h"
#include "camera.h"
#include "libs/ini.h"
using namespace  std;
using namespace reactphysics3d;
class Level
{
public:
    Level();
    void load(string mapName,Camera &player);
    void render(Camera &player);
    void clear();
private:
    std::vector<Block*>blocks;
    std::vector<Block*>floorVec;
    std::vector<Block*>ceilingVec;
    std::vector<Sprite>sprites;
    void floor(int size,string texture);
    void ceiling(int size,string texture);
};

#endif // MAP_H
