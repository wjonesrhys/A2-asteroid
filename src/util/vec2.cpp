#include <vec2.hpp>

Vec2::Vec2() :
    m_x(0),
    m_y(0) 
{}

Vec2::~Vec2() 
{

};

Vec2::Vec2(float x) :
    m_x(x),
    m_y(x)
{}

Vec2::Vec2(float x, float y) :
    m_x(x),
    m_y(y)
{}

Vec2::Vec2(sf::Vector2f vec2f) :
    m_x(vec2f.x),
    m_y(vec2f.y)
{}

Vec2::Vec2(sf::Vector2i vec2i) :
    m_x(vec2i.x),
    m_y(vec2i.y)
{}

Vec2::Vec2(sf::Vector2u vec2u) :
    m_x(vec2u.x),
    m_y(vec2u.y)
{}

Vec2::operator sf::Vector2f()
{
    return sf::Vector2f(m_x, m_y);
}

Vec2::operator sf::Vector2i()
{
    return sf::Vector2i(m_x, m_y);
}

Vec2::operator sf::Vector2u()
{
    return sf::Vector2u(m_x, m_y);
}

Vec2 Vec2::operator + (const Vec2& right) const
{
    return Vec2(this->m_x + right.m_x, this->m_y + right.m_y);
}

Vec2 Vec2::operator - (const Vec2& right) const
{
    return Vec2(this->m_x - right.m_x, this->m_y - right.m_y);
}

Vec2 Vec2::operator * (const Vec2& right) const 
{
    return Vec2(this->m_x * right.m_x, this->m_y * right.m_y);
}

Vec2 Vec2::operator / (const Vec2& right) const
{
    return Vec2(this->m_x / right.m_x, this->m_y / right.m_y);
}

Vec2 Vec2::operator / (const float scalar) const
{
    return Vec2(this->m_x/scalar, this->m_y/scalar);
}

Vec2 Vec2::operator * (const float scalar) const
{
    return Vec2(this->m_x*scalar, this->m_y*scalar);
}

bool Vec2::operator == (const Vec2& right) const
{
    return (m_x == right.m_x) && (m_y == right.m_y);
}

bool Vec2::operator != (const Vec2& right) const 
{
    return (m_x != right.m_x) || (m_y != right.m_y);
}

Vec2& Vec2::operator += (const Vec2& right)
{
    this->m_x += right.m_x;
    this->m_y += right.m_y;
    return *this;
}

Vec2& Vec2::operator -= (const Vec2& right)
{
    this->m_x -= right.m_x;
    this->m_y -= right.m_y;
    return *this;
}

Vec2& Vec2::operator *= (const Vec2& right)
{
    this->m_x *= right.m_x;
    this->m_y *= right.m_y;
    return *this;
}

Vec2& Vec2::operator /= (const Vec2& right)
{
    this->m_x /= right.m_x;
    this->m_y /= right.m_y;
    return *this;
}

Vec2& Vec2::operator *= (const float scalar)
{
    this->m_x *= scalar;
    this->m_y *= scalar;
    return *this;
}

Vec2& Vec2::operator /= (const float scalar)
{
    this->m_x /= scalar;
    this->m_y /= scalar;
    return *this;
}

void Vec2::print() {
    std::cout << "vector: " << m_x << ", " << m_y << std::endl;
}