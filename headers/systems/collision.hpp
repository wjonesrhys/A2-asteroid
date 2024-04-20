// #ifndef COLLISION_HPP
// #define COLLISION_HPP

// #include <SFML/Graphics.hpp>
// #include <rectplayer.hpp>
// #include <circplayer.hpp>
// #include <cmath>

// class Collision
// {
//     private:
        
//     public:
//         Collision();
//         ~Collision();

//         void checkAndResolveCollisionWithWalls(
//             std::vector<sf::RectangleShape>& rectangles,
//             sf::Vector2u windowSize
//         );
//         void checkAndResolveCollisionWithWalls(
//             std::vector<sf::CircleShape>& circles,
//             sf::Vector2u windowSize
//         );

//         void checkAllCircles(std::vector<CircPlayer*>& circles);
//         void checkAllRectangles(std::vector<RectPlayer*>& rectangles);
//         void checkAllCirclesRectangles(std::vector<CircPlayer*>& circles, std::vector<RectPlayer*>& rectangles);
//         void resolveAllRectangles(std::vector<RectPlayer*>& rectangles);

//         void checkRectangles(RectPlayer& r1, RectPlayer& r2);
//         void checkCircles(CircPlayer& c1, CircPlayer& c2);
//         void checkCircRect(CircPlayer& circle, RectPlayer& rectangle);
        
//         bool isCCCollision(CircPlayer& c1, CircPlayer& c2);
//         bool isCCCollision(sf::Vector2f r1Pos, float r1Radius, sf::Vector2f r2Pos, float r2Radius);

//         bool isAABBCollision(RectPlayer* r1, RectPlayer* r2);
//         void resolvePosition(RectPlayer* rectangle, float ox, float oy, float absx, float absy);
        
//         bool oldAABBCollision(RectPlayer& r1, RectPlayer& r2);
//         bool isAABBCollision(sf::Vector2f r1Pos, float r1Width, float r1Height, sf::Vector2f r2Pos, float r2Width, float r2Height);

//         bool isCircRectCollision(CircPlayer& c1, RectPlayer& r1);
//         bool isCircRectCollision(sf::Vector2f cPos, float cRadius, sf::Vector2f rPos, float rWidth, float rHeight);
// };
// #endif