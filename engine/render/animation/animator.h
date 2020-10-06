#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <map>
#include <vector>
#include "animation2d.h"
namespace PFE
{
    template<class T>
    class Animator
    {
        public:
            void addAnimation(T *animation,std::string animationName);
            void playAnimation(std::string animationName,ShaderProgram *shaderProgram,float speed);
        private:
            std::map<std::string,T*> animations;
            bool isAnimationExist(std::string animationName);
    };
}
template <class T>
bool PFE::Animator<T>::isAnimationExist(std::string animationName)
{
    typename std::map<std::string,T*>::iterator animationsIterator;
    animationsIterator = animations.find(animationName);
    if(animationsIterator == animations.end())
        return  false;
    return true;
}
template<class T>
void PFE::Animator<T>::playAnimation(std::string animationName,ShaderProgram *shaderProgram,float speed)
{
       try
       {
           if(!isAnimationExist(animationName))
               throw "Animation not found.";
           animations[animationName]->setShader(shaderProgram);
           animations[animationName]->play(speed);
       }
       catch (const char* e)
       {
           std::cout<<e<<std::endl;
       }
}
template<class T>
void PFE::Animator<T>::addAnimation(T *animation,std::string animationName)
{
    try
    {
        if(isAnimationExist(animationName))
            throw "Animation with this name exist";
        animations[animationName] = animation;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
}
#endif // ANIMATOR_H
