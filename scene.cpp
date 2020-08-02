#include "scene.h"


double dTime = 0.0f;
float lastFrame = 0.0f;
Camera player(0.0f,0.0f,0.0f,0.05);
Render &mRender =  Render::createRender();
//PhysicsWorld *world;
//PhysicsCommon physicsCommon;
void Scene::start()
{

   // PhysicsWorld::WorldSettings settings;
   // settings.gravity = Vector3(0,9.81,0);
   //settings.defaultVelocitySolverNbIterations =20;
   //settings.isSleepingEnabled = true;
   // world = physicsCommon.createPhysicsWorld(settings);

    mRender.load("maps/map1.ini",player);
}
void Scene::update()
{
    GLfloat currentFrame = glfwGetTime();
    dTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    //world->update(dTime);
    mRender.render(player);

}
void Scene::mouseCallback(GLFWwindow *window,double xpos, double ypos)
{
    player.mouse(window,xpos,ypos);
}
void Scene::keyboard(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window,GL_TRUE);
    }
    player.move(window,key,scancode,action,mode,dTime);
}
void Scene::clear()
{
    //physicsCommon.destroyPhysicsWorld(world);
    //map.clear();
}
