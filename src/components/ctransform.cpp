#include <ctransform.hpp>

CTransform::CTransform()
{

}

CTransform::CTransform(Vec2 pos, Vec2 speed) :
    pos(pos),
    prevPos(pos),
    speed(speed)
{

}

CTransform::~CTransform()
{
    
}