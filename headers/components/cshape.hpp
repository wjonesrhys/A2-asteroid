#ifndef CSHAPE_HPP
#define CSHAPE_HPP

#include <vec2.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <memory>

class CShape 
{
    public:
        std::shared_ptr<sf::Shape> shape = nullptr;
        // sf::CircleShape shape;
        std::string shapeType;

        CShape();
        CShape(Vec2 pos, sf::Color color, float radius);
        CShape(Vec2 pos, sf::Color color, float radius, int numOfPoints);
        CShape(Vec2 pos, sf::Color color, Vec2 size);
        CShape(std::string& shapeType);

        ~CShape();
};

#endif
