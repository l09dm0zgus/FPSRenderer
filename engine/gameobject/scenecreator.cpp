#include "scenecreator.h"

void PFE::SceneCreator::create(std::string mapName)
{
    scene = new SceneFolder();
    
    PhysicsWorldComponent* physicsWorld = new PhysicsWorldComponent();
    lightData = new LightData();
    LightSource* directionalLight = new LightSource();
    SpotLight* spotLight = new SpotLight();
    directionalLight->setPosition(glm::vec3(3.0f, 1.0f, 3.0f));
    directionalLight->setAmbient(glm::vec3(0.05f,0.04f,0.07f));
    directionalLight->setDiffuse(glm::vec3(0.01f, 0.01f, 0.01f));
    directionalLight->setSpecular(glm::vec3(0.0f, 0.0f, 0.0f));
    lightData->addDirectLight(directionalLight);
    scene->addChild("Walls",new SceneFolder());
    scene->addChild("CeilingAndFloor",new SceneFolder());
    mINI::INIFile file(mapName);
    mINI::INIStructure ini;
    if (!file.read(ini))
    {
        cout << "ERROR:"<<mapName<< " not found.Please reinstall program!!!" << endl;
        exit(-1);
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
    renderEnemyComponent->setLightData(lightData);
    renderEnemyComponent->setCamera(camera);
    enemy->addComponent("RenderComponent", renderEnemyComponent);
    enemy->setSize(glm::vec3(1.0f,1.0f,1.0f));
    enemy->setPosition(glm::vec3(2.0f,0.5f,4.0f));
    scene->addChild("enemy",enemy);
   
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
            //not working on my pc
           // block->addTexture(Path::getImageFilePath("container2neon.png"));
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
            renderWallComponent->setLightData(lightData);
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
            spotLight->setAmbient(glm::vec3(0.4, 0.2f, 0.3f));
            spotLight->setDiffuse(glm::vec3(0.3f, 0.6f, 0.05f));
            spotLight->setSpecular(glm::vec3(0.0f, 0.0f, 0.0f));
            spotLight->setPosition(camera->getPosition());
            spotLight->setDirection(camera->getForwardVector());
            spotLight->setConstant(1.0f);
            spotLight->setQuadratic(0.032);
            spotLight->setLinear(0.09);
            spotLight->setCutOff(glm::cos(glm::radians(12.5f)));
            spotLight->setOuterCutOff(glm::cos(glm::radians(15.0f)));
            lightData->addSpotLight(spotLight);
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
      renderComponent->setLightData(lightData);
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
      renderComponent->setLightData(lightData);
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
