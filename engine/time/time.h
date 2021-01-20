#ifndef TIME_H
#define TIME_H
#include<GLFW/glfw3.h>
#include <iostream>
#include <reactphysics3d/reactphysics3d.h>
namespace PFE
{
    class Time
    {
        public:
            void showFPS();
            void sleep(int ms);
            void start();
            long double getDeltaTime();
            void updatePhysicsWorld(rp3d::PhysicsWorld *world);
            long double getFactor();
        private:
            double lastTime;
            double currentTime;
            int frames = 0;
            const float timeStep = 1.0f/120.0f;
            long double deltaTime = 0;
            long double accumulator = 0;
            long double factor = 0;
    };
}


#endif // TIME_H
