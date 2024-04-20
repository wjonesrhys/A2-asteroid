#ifndef CTRANSFORM_HPP
#define CTRANSFORM_HPP

#include <vec2.hpp>

class CTransform 
{

    public:
        Vec2 pos = Vec2(0,0);
        Vec2 prevPos = Vec2(0,0);
        Vec2 scale = Vec2(0,0);
        Vec2 speed = Vec2(0,0);
        float angle = 0;
        
        CTransform();
        CTransform(Vec2 pos, Vec2 speed);
        ~CTransform();
};

#endif