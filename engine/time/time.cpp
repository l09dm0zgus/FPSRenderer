#include "time.h"
#include <chrono>
#include <thread>

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

void PFE::Time::sleep(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
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
    getDeltaTime();
    while(accumulator >= timeStep)
    {
        world->update(timeStep);
        accumulator -= timeStep;
    }
    factor = accumulator / timeStep;
}

long double PFE::Time::getFactor()
{
    return factor;
}
