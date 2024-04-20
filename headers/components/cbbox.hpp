#ifndef CBBOX_HPP
#define CBBOX_HPP

#include <vec2.hpp>

class CBBox 
{
    public:
        Vec2 size = Vec2(0,0);
        float halfWidth;
        float halfHeight;

        CBBox();
        CBBox(Vec2 size);

        ~CBBox();
};

#endif