#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <map>
#include "animation2d.h"
namespace PFE
{
    template<class T>
    class Animator
    {
        public:
            void addAnimation(T *animation,std::string animationName);
            void playAnimation(std::string animationName,float speed);
            void setShaderProgram(Shader *shaderProgram);
        private:
            std::map<std::string,T*> animations;
            typename std::map<std::string,T*>::iterator animationsIterator;
    };
}
template<class T>
void PFE::Animator<T>::setShaderProgram(Shader *shaderProgram)
{
    for(auto &animation:animations)
    {
        animation.second->setShader(shaderProgram);
    }
}
template<class T>
void PFE::Animator<T>::playAnimation(std::string animationName,float speed)
{
    try
    {
        animationsIterator = animations.find(animationName);
        if(animationsIterator != animations.end())
            animationsIterator->second->play(speed);
        else
            throw "Not founded animation.";
    }
    catch (const char * e)
    {
        std::cout<<e<<std::endl;
    }
}
template<class T>
void PFE::Animator<T>::addAnimation(T *animation,std::string animationName)
{
    //animations.insert(std::pair<std::string,T&>(animationName,animation));
    animations[animationName] = animation;
}
#endif // ANIMATOR_H
