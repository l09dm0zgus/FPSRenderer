#include "render.h"
PFE::Render& PFE::Render::createRender()
{
    static Render instance;
    return instance;
}
void PFE::Render::load(string mapName)
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
     Sprite *spr = new Sprite;
     spr->setSize(glm::vec3(1.0f,1.0f,1.0f));
     spr->setShaderFile("shaders/SpriteVS.glsl","shaders/SpriteFS.glsl");
     spr->addTexture("spr.png");
     spr->loadTextures();
     spr->setPosition(glm::vec3(2.0f,0.5f,4.0f));
     for(int i = 1;i<size+1;i++)
     {
         if(ini.get(to_string(i)).get("type") == "wall")
         {
             Block *wall = new Block;
             wall->setSize(glm::vec3(1.0f,1.0f,1.0f));
             wall->setShaderFile("shaders/BlockVS.glsl","shaders/BlockFS.glsl");
             wall->addTexture(blockTexture);
             wall->addTexture(blockTexture);
             wall->loadTextures();
             glm::vec3 pos ;
             pos.x = stoi(ini.get(to_string(i)).get("x"));
             pos.y = stoi(ini.get(to_string(i)).get("y"));
             pos.z = stoi(ini.get(to_string(i)).get("z"));
             wall->setPosition(pos);
             renderObjects.push_back(wall);

         }
         if(ini.get(to_string(i)).get("type") == "player")
         {
             glm::vec3 pos ;
             player = new Camera(0,0,0,0.5);
             pos.x = stoi(ini.get(to_string(i)).get("x"));
             pos.y = stoi(ini.get(to_string(i)).get("y"));
             pos.z = stoi(ini.get(to_string(i)).get("z"));
             player->setPosition(pos);
             //renderObjects.push_back(spr);
         }
     }
    //sprites add last
    renderObjects.push_back(spr);
}
void PFE::Render::ceiling(int size,string texture)
{

      Block *ceiling = new Block;
      ceiling->setSize(glm::vec3(size,1.0,size));
      ceiling->setShaderFile("shaders/BlockVS.glsl","shaders/BlockFS.glsl");
      ceiling->addTexture(texture);
      ceiling->addTexture(texture);
      ceiling->loadTextures();
      ceiling->setPosition(glm::vec3(1.0f,2.0f,1.0f));
      renderObjects.push_back(ceiling);
}
void PFE::Render::floor(int size, string texture)
{

      Block *floor = new Block;
      floor->setSize(glm::vec3(size,1.0,size));
      floor->setShaderFile("shaders/BlockVS.glsl","shaders/BlockFS.glsl");
      floor->addTexture(texture);
      floor->addTexture(texture);
      floor->loadTextures();
      floor->setPosition(glm::vec3(1.0f,0.0f,1.0f));
      renderObjects.push_back(floor);


}
void PFE::Render::setViewportSize(glm::vec2 viewportSize)
{
    this->viewportSize = viewportSize;
}
void PFE::Render::render()
{
//   for(auto &object:renderObjects)
//   {
//      object->setViewportProperties(player->getView(),viewportSize);
//      object->render();
//   }
    //s[0]->setViewportProperties(player->getView(),viewportSize);
    //s[0]->render();
    for(int i=0;i<renderObjects.size();i++)
    {
        renderObjects[i]->setViewportProperties(player->getView(),viewportSize);
        renderObjects[i]->render();
    }
   player->mouse();
   player->move();
}
void PFE::Render::clear()
{
    for(auto &object:renderObjects)
    {
        delete object;
        object = nullptr;
    }
    delete player;
    player = nullptr;
}
