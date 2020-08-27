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
        private:
            std::map<std::string,T> animations;
    };
}


#endif // ANIMATOR_H
