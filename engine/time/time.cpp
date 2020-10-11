#include "time.h"

void PFE::Time::start()
{
    lastTime = glfwGetTime();
}
void PFE::Time::showFPS()
{
    currentTime = glfwGetTime();
    frames++;
    if ( currentTime - lastTime >= 1.0 )
    {
        printf("%i FPS\n", frames);
        frames = 0;
        lastTime = currentTime ;
    }
}
long double PFE::Time::getDeltaTime()
{
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    accumulator += deltaTime;
    return deltaTime;
}
void PFE::Time::updatePhysicsWorld(rp3d::PhysicsWorld *world)
{
    while(accumulator >= timeStep)
    {
        world->update(timeStep);
        accumulator -= timeStep;
    }
}
