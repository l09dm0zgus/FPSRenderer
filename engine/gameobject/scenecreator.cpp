#include "scenecreator.h"

void PFE::SceneCreator::create(std::string mapName)
{
    scene = new SceneFolder();
    scene->addChild("Walls",new SceneFolder());
    scene->addChild("CeilingAndFloor",new SceneFolder());
    mINI::INIFile file(mapName);
    mINI::INIStructure ini;
    if (!file.read(ini))
    {
        cout << "File not found!!!" << endl;
    }
        
    int size = stoi(ini.get("SystemInfo").get("mapObjects"));
    string blockTexture = Path::getImageFilePath(ini.get("SystemInfo").get("textureWall"));
    ceiling(size,blockTexture);
    floor(size,blockTexture);

    Sprite *spr = new Sprite;
    Enemy *enemy = new Enemy();

    spr->setShaderFile(Path::getShaderFilePath("SpriteVS.glsl"), Path::getShaderFilePath("SpriteFS.glsl"));
    spr->addTexture(Path::getImageFilePath("spr.png"));
    spr->loadTextures();
    enemy->addRenderObject(spr);
    enemy->setSize(glm::vec3(1.0f,1.0f,1.0f));
    enemy->setPosition(glm::vec3(2.0f,0.5f,4.0f));
    scene->addChild("enemy",enemy);
    for(int i = 1;i<size+1;i++)
    {
        if(ini.get(to_string(i)).get("type") == "wall")
        {
            Cube *block = new Cube;
            Wall *wall = new Wall();
            PhysicsWorldComponent* component = new PhysicsWorldComponent();
            block->setShaderFile(Path::getShaderFilePath("BlockVS.glsl"), Path::getShaderFilePath("BlockFS.glsl"));
            block->addTexture(blockTexture);
            block->addTexture(blockTexture);
            block->loadTextures();
            glm::vec3 pos ;
            pos.x = stoi(ini.get(to_string(i)).get("x"));
            pos.y = stoi(ini.get(to_string(i)).get("y"));
            pos.z = stoi(ini.get(to_string(i)).get("z"));
            wall->addRenderObject(block);
            wall->setSize(glm::vec3(1.0f,1.0f,1.0f));
            wall->setPosition(pos);
            wall->addComponent("PhysicsWorld",component);
            scene->getChild("Walls")->addChild("wall"+to_string(i),wall);
        }
        if(ini.get(to_string(i)).get("type") == "player")
        {
            glm::vec3 pos ;

            Player *player = new Player();
            pos.x = stoi(ini.get(to_string(i)).get("x"));
            pos.y = stoi(ini.get(to_string(i)).get("y"));
            pos.z = stoi(ini.get(to_string(i)).get("z"));
            Camera *camera = new Camera(pos.x,pos.y,pos.z,0.5);
            player->setCamera(camera);
            player->setPosition(pos);
            scene->getChild("CeilingAndFloor")->getChild("floor")->addChild("player",player);
        }
    }
    scene->load();

}
PFE::GameObject *PFE::SceneCreator::getSceneGraph()
{
    return scene;
}
void PFE::SceneCreator::ceiling(int size,string texture)
{

      Cube *ceiling = new Cube;
      Wall *wall = new Wall();
      ceiling->setShaderFile(Path::getShaderFilePath("BlockVS.glsl"), Path::getShaderFilePath("BlockFS.glsl"));
      ceiling->addTexture(texture);
      ceiling->addTexture(texture);
      ceiling->loadTextures();
      wall->addRenderObject(ceiling);
      wall->setSize(glm::vec3(size,1.0,size));
      wall->setPosition(glm::vec3(1.0f,2.0f,1.0f)); 
      scene->getChild("CeilingAndFloor")->addChild("ceiling",wall);

}
void PFE::SceneCreator::floor(int size, string texture)
{

      Cube *floor = new Cube;
      Wall *wall = new Wall();

      floor->setShaderFile(Path::getShaderFilePath("BlockVS.glsl"),Path::getShaderFilePath("BlockFS.glsl"));
      floor->addTexture(texture);
      floor->addTexture(texture);
      floor->loadTextures();
      wall->addRenderObject(floor);
      wall->setSize(glm::vec3(size,1.0,size));
      wall->setPosition(glm::vec3(1.0f,0.0f,1.0f));
      scene->getChild("CeilingAndFloor")->addChild("floor",wall);
}
glm::mat4 PFE::SceneCreator::getCameraView()
{
    return scene->getChild("CeilingAndFloor")->getChild("floor")->getChild("player")->getView();
}
