#ifndef VEC2_HPP
#define VEC2_HPP

#include <SFML/System/Vector2.hpp>
#include <iostream>

class Vec2 {
    private:

    public:
        float m_x;
        float m_y;

        Vec2();
        Vec2(float x);
        Vec2(float x, float y);
        Vec2(sf::Vector2f vec2f);
        Vec2(sf::Vector2i vec2i);
        Vec2(sf::Vector2u vec2u);
        ~Vec2();

        operator sf::Vector2f();
        operator sf::Vector2i();
        operator sf::Vector2u();

        Vec2 operator + (const Vec2& right) const;
        Vec2 operator - (const Vec2& right) const;
        Vec2 operator / (const Vec2& right) const;
        Vec2 operator * (const Vec2& right) const;

        Vec2 operator / (const float scalar) const;
        Vec2 operator * (const float scalar) const;

        bool operator == (const Vec2& right) const;
        bool operator != (const Vec2& right) const;
        
        Vec2& operator += (const Vec2& right);
        Vec2& operator -= (const Vec2& right);
        Vec2& operator /= (const Vec2& right);
        Vec2& operator *= (const Vec2& right);

        Vec2& operator *= (const float scalar);
        Vec2& operator /= (const float scalar);
        
        void print();

};

#endif