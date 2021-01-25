#include "scenecreator.h"

void PFE::SceneCreator::create(std::string mapName)
{
    scene = new SceneFolder();
    
    PhysicsWorldComponent* physicsWorld = new PhysicsWorldComponent();
    sceneLight = new LightSource();
    sceneLight->setPosition(glm::vec3(2.0f, 1.6f, 3.0f));
    sceneLight->setSize(glm::vec3(0.1f, 0.1f, 0.1f));
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
    RenderObjectComponent* renderEnemyComponent = new RenderObjectComponent();
    renderEnemyComponent->setRenderObject(spr);
    renderEnemyComponent->setLightSource(sceneLight);
    renderEnemyComponent->setCamera(camera);
    enemy->addComponent("RenderComponent", renderEnemyComponent);
    enemy->setSize(glm::vec3(1.0f,1.0f,1.0f));
    enemy->setPosition(glm::vec3(2.0f,0.5f,4.0f));
    scene->addChild("enemy",enemy);
    scene->addChild("light", sceneLight);
    for(int i = 1;i<size+1;i++)
    {
        if(ini.get(to_string(i)).get("type") == "wall")
        {
            Cube *block = new Cube();
            Wall *wall = new Wall();
            RigidBodyComponent* rigidBodyComponent = new RigidBodyComponent();
            block->setShaderFile(Path::getShaderFilePath("BlockVS.glsl"), Path::getShaderFilePath("BlockFS.glsl"));
            block->addTexture(Path::getImageFilePath("container2.png"));
            block->addTexture(Path::getImageFilePath("container2diffuse.png"));
            block->addTexture(Path::getImageFilePath("container2neon.png"));
            block->loadTextures();
            glm::vec3 pos ;
            pos.x = stoi(ini.get(to_string(i)).get("x"));
            pos.y = stoi(ini.get(to_string(i)).get("y"));
            pos.z = stoi(ini.get(to_string(i)).get("z"));
            wall->addRenderObject(block);
            wall->setSize(glm::vec3(1.0f,1.0f,1.0f));
            wall->setPosition(pos);
            RenderObjectComponent* renderWallComponent = new RenderObjectComponent();
            renderWallComponent->setRenderObject(block);
            renderWallComponent->setLightSource(sceneLight);
            renderWallComponent->setCamera(camera);
            wall->addComponent("RenderComponent", renderWallComponent);
            wall->addComponent("PhysicsWorld", physicsWorld);
            rigidBodyComponent->setBody(physicsWorld->createRigidbody(glmVectorToReactPhysicsVector(pos), rp3d::Quaternion::identity()));
            rigidBodyComponent->addBoxShape(physicsWorld->createBoxShape(rp3d::Vector3(0.5f,0.5f,0.5f)));
            wall->addComponent("RigidBody", rigidBodyComponent);
            scene->getChild("Walls")->addChild("wall"+to_string(i),wall);
        }
        if(ini.get(to_string(i)).get("type") == "player")
        {
            glm::vec3 pos ;
            Player *player = new Player();
            RigidBodyComponent* rigidBodyComponent = new RigidBodyComponent();
            pos.x = stoi(ini.get(to_string(i)).get("x"));
            pos.y = stoi(ini.get(to_string(i)).get("y"));
            pos.z = stoi(ini.get(to_string(i)).get("z"));
            camera = new Camera(pos.x, pos.y, pos.z, 0.5);
            player->addComponent("PhysicsWorld", physicsWorld);
            player->setCamera(camera);
            player->setPosition(pos);
            rigidBodyComponent->setBody(physicsWorld->createRigidbody(glmVectorToReactPhysicsVector(pos), rp3d::Quaternion::identity()));
            rigidBodyComponent->addCapsuleShape(physicsWorld->createCapsuleShape(0.5f,1.0f));
            //in future will be deleted when will be refactored this class
            rigidBodyComponent->setIsPlayer(true);
            player->addComponent("RigidBody", rigidBodyComponent);
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
      RenderObjectComponent* renderComponent = new RenderObjectComponent();
      renderComponent->setRenderObject(ceiling);
      renderComponent->setLightSource(sceneLight);
      renderComponent->setCamera(camera);
      wall->addComponent("RenderComponent", renderComponent);
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
      RenderObjectComponent* renderComponent = new RenderObjectComponent();
      renderComponent->setRenderObject(floor);
      renderComponent->setLightSource(sceneLight);
      renderComponent->setCamera(camera);
      wall->addComponent("RenderComponent", renderComponent);
      wall->setSize(glm::vec3(size,1.0,size));
      wall->setPosition(glm::vec3(1.0f,0.0f,1.0f));
      scene->getChild("CeilingAndFloor")->addChild("floor",wall);
}

glm::mat4 PFE::SceneCreator::getCameraView()
{
    return scene->getChild("CeilingAndFloor")->getChild("floor")->getChild("player")->getView();
}
