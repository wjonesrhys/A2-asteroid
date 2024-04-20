#include <cbbox.hpp>

CBBox::CBBox() :
    halfWidth(0),
    halfHeight(0)
{

}

CBBox::CBBox(Vec2 size) :
    halfWidth(size.m_x/2),
    halfHeight(size.m_y/2)
{
    this->size = size;
}

CBBox::~CBBox()
{
    
}