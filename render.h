#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
//#include <reactphysics3d/reactphysics3d.h>
#include "block.h"
#include "sprite.h"
#include "camera.h"
#include "libs/ini.h"
using std::vector;
using namespace PFE;
/**
 * @brief The Render class  Singleton class.We can have ONE object class.
 */
class Render
{
public:

    void load(string mapName,Camera &player);
    void render(Camera &player);
    static Render& createRender();
     ~Render(){clear();};
private:
    void clear();
    Render(){};
    //Render& operator=(const Render&);
    Render(const Render&);
    vector<Block*>blocks;
    vector<Block*>floorVec;
    vector<Block*>ceilingVec;
    vector<Sprite>sprites;
    void floor(int size,string texture);
    void ceiling(int size,string texture);
};

#endif // MAP_H
