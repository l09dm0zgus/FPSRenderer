#include "map.h"

Level::Level()
{

}
void Level::load(string mapName,Camera &player)
{
     mINI::INIFile file(mapName);
     mINI::INIStructure ini;
     if(!file.read(ini))
         cout<<"File not found!!!"<<endl;
     int size = stoi(ini.get("SystemInfo").get("mapObjects"));

     string blockTexture = ini.get("SystemInfo").get("textureWall");
     ceiling(size,blockTexture);
     floor(size,blockTexture);

    // ceilingThr.join();
   //  floorThr.join();
     Sprite spr;
     spr.setSize(glm::vec3(1.0f,1.0f,1.0f));
     spr.setShaderFile("shaders/SpriteVS.glsl","shaders/SpriteFS.glsl");
     spr.loadTextures("spr.png");
   //  spr.setTilePosition(6,4,1,1);
     spr.setPosition(glm::vec3(2.0f,0.5f,4.0f));
     sprites.push_back(spr);
     for(int i = 1;i<size+1;i++)
     {
         if(ini.get(to_string(i)).get("type") == "wall")
         {
             Block *wall = new Block;
             wall->setSize(glm::vec3(1.0f,1.0f,1.0f));
             wall->setShaderFile("shaders/BlockVS.glsl","shaders/BlockFS.glsl");
             wall->loadTextures(blockTexture,"lukas.jpg");
             glm::vec3 pos ;
             pos.x = stoi(ini.get(to_string(i)).get("x"));
             pos.y = stoi(ini.get(to_string(i)).get("y"));
             pos.z = stoi(ini.get(to_string(i)).get("z"));
             wall->setPosition(pos);
             blocks.push_back(wall);
         }
         if(ini.get(to_string(i)).get("type") == "player")
         {
             glm::vec3 pos ;
             pos.x = stoi(ini.get(to_string(i)).get("x"));
             pos.y = stoi(ini.get(to_string(i)).get("y"));
             pos.z = stoi(ini.get(to_string(i)).get("z"));
             player.setPosition(pos);
         }
     }


}
void Level::ceiling(int size,string texture)
{

      Block *ceiling = new Block;
      ceiling->setSize(glm::vec3(size,1.0,size));
      ceiling->setShaderFile("shaders/BlockVS.glsl","shaders/BlockFS.glsl");
      ceiling->loadTextures(texture,"lukas.jpg");
      ceiling->setPosition(glm::vec3(1.0f,2.0f,1.0f));
      ceilingVec.push_back(ceiling);
}
void Level::floor(int size, string texture)
{

      Block *floor = new Block;
      floor->setSize(glm::vec3(size,1.0,size));
      floor->setShaderFile("shaders/BlockVS.glsl","shaders/BlockFS.glsl");
      floor->loadTextures(texture,"lukas.jpg");
      floor->setPosition(glm::vec3(1.0f,0.0f,1.0f));
      floorVec.push_back(floor);


}
void Level::render(Camera &player)
{
    for(size_t i = 0;i<floorVec.size();i++)
    {
        ceilingVec[i]->render(player);
        floorVec[i]->render(player);
    }
    for(size_t i = 0;i<blocks.size();i++)
    {
        // player.collision(blocks[i]->getPosition(),blocks[i]->getSize());
         blocks[i]->collision(player);
         blocks[i]->render(player);
    }

    for(size_t i =0;i<sprites.size();i++)
    {


            sprites[i].render(player);
          //  sprites[i].setTilePosition(6,4,j,j);



    }
}

void Level::clear()
{
    for(size_t i = 0;i<blocks.size();i++)
    {
        delete blocks[i];
        blocks[i] = nullptr;
    }
    for(size_t i = 0;i<floorVec.size();i++)
    {
        delete ceilingVec[i];
        delete  floorVec[i];
        ceilingVec[i] = nullptr;
        floorVec[i] = nullptr;
    }
}
