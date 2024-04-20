#include <cshape.hpp>

CShape::CShape()
{

}

CShape::CShape(Vec2 pos, sf::Color color, float radius, int points) 
{
    sf::CircleShape tempCircle = sf::CircleShape(radius);
    tempCircle.setOrigin(Vec2(radius));
    tempCircle.setPosition(pos);
    tempCircle.setFillColor(color);
    tempCircle.setRadius(radius);
    tempCircle.setPointCount(points);
    shape = std::make_shared<sf::CircleShape>(tempCircle);
}

CShape::CShape(Vec2 pos, sf::Color color, float radius) 
{
    sf::CircleShape tempCircle = sf::CircleShape(radius);
    tempCircle.setOrigin(Vec2(radius));
    tempCircle.setPosition(pos);
    tempCircle.setFillColor(color);
    tempCircle.setRadius(radius);
    shape = std::make_shared<sf::CircleShape>(tempCircle);
}

CShape::CShape(Vec2 pos, sf::Color color, Vec2 size)
{
    sf::RectangleShape tempRect = sf::RectangleShape(size);
    tempRect.setOrigin(Vec2(size.m_x/2, size.m_y/2));
    tempRect.setPosition(pos);
    tempRect.setFillColor(color);
    tempRect.setSize(size);
    shape = std::make_shared<sf::RectangleShape>(tempRect);
}

CShape::CShape(std::string& shapeType) 
    : shapeType(shapeType)
{
    sf::CircleShape tempCircle = sf::CircleShape(20.0f);
    shape = std::make_shared<sf::CircleShape>(tempCircle);
}


CShape::~CShape()
{
    // delete shape;
    std::cout << "shape deleted" << std::endl;
}