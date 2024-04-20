// #include <collision.hpp>

// Collision::Collision() 
// {
    
// }

// Collision::~Collision() 
// {

// }

// void Collision::checkAndResolveCollisionWithWalls(std::vector<sf::RectangleShape>& rectangles, sf::Vector2u windowSize) 
// {
//     for (auto& r : rectangles) {
//         sf::Vector2f position = r.getPosition();
//         float halfWidth = r.getSize().x/2;
//         float halfHeight = r.getSize().y/2;

//         // keep circle inside the window
//         if (position.x < halfWidth) {
//             position.x = halfWidth;
//         } 
//         else if (position.x > windowSize.x - halfWidth){
//             position.x = windowSize.x - halfWidth;
//         }

//         if (position.y < halfHeight){
//             position.y = halfHeight;
//         } 
//         else if (position.y > windowSize.y - halfHeight){
//             position.y = windowSize.y - halfHeight;
//         }    
//         r.setPosition(position);
//     }
// }

// void Collision::checkAndResolveCollisionWithWalls(std::vector<sf::CircleShape>& circles, sf::Vector2u windowSize) 
// {
//     for (auto& c : circles) {
//         sf::Vector2f position = c.getPosition();
//         float radius = c.getRadius();

//         // keep circle inside the window
//         if (position.x < radius) {
//             position.x = radius;
//         } 
//         else if (position.x > windowSize.x - radius){
//             position.x = windowSize.x - radius;
//         }

//         if (position.y < radius){
//             position.y = radius;
//         } 
//         else if (position.y > windowSize.y - radius){
//             position.y = windowSize.y - radius;
//         }    
//         c.setPosition(position);
//     }
// }

// /*
//     Loop through collections for collisions.
// */

// void Collision::checkAllCircles(std::vector<CircPlayer*>& circles) {
//     int count = 0;
//     for (CircPlayer* c1 : circles) {
//         for (int i=0; i < circles.size(); i++) {
//             if (i!=count) {
//                 if (isCCCollision(*c1, *circles.at(i))) {
//                     c1->setColliding(true);
//                     circles.at(i)->setColliding(true);
//                     break;
//                 }
//                 c1->setColliding(false);
//             }
//         }
//         count++;
//     }
// }

// void Collision::checkAllRectangles(std::vector<RectPlayer*>& rectangles) {
//     int count = 1;
//     // r1, compared to r2 and then static
//     // r2, compared with static
//     for (RectPlayer* r1 : rectangles) {
//         for (int i=count; i < rectangles.size(); i++) {
//             if (isAABBCollision(r1, rectangles.at(i))) {
//                 r1->setColliding(true);
//                 rectangles.at(i)->setColliding(true);
//                 break;
//             }
//         }
//         count++;
//     }
// }

// void Collision::checkAllCirclesRectangles(std::vector<CircPlayer*>& circles, std::vector<RectPlayer*>& rectangles) {
//     for (CircPlayer* c1 : circles) {
//         for (RectPlayer* r1 : rectangles) {
//             if (isCircRectCollision(
//                 c1->getPosition(), c1->getRadius(), 
//                 r1->getPosition(), r1->getHalfWidth(), r1->getHalfHeight())) 
//             {

//                 c1->setColliding(true);
//                 r1->setColliding(true);
//             }
//         }
//     }
// }

// void Collision::resolveAllRectangles(std::vector<RectPlayer*>& rectangles) {
//     // for (RectPlayer r1 )
// }

// /*
//     Individual collision detection.
// */

// void Collision::checkCircles(CircPlayer& c1, CircPlayer& c2) 
// {
//     if (isCCCollision(c1.getPosition(), c1.getRadius(), c2.getPosition(), c2.getRadius()))
//     {
//         c1.setColliding(true);
//         c2.setColliding(true);
//     }
// }

// void Collision::checkRectangles(RectPlayer& r1, RectPlayer& r2) 
// {

//     if (
//         isAABBCollision(
//         r1.getPosition(), r1.getHalfWidth(), r1.getHalfHeight(), 
//         r2.getPosition(), r2.getHalfWidth(), r2.getHalfHeight()
//         )
//     )
//     {
//         r1.setColliding(true);
//         r2.setColliding(true);
//     }
// }

// void Collision::checkCircRect(CircPlayer& c1, RectPlayer& r1) 
// {
//     if (isCircRectCollision(
//         c1.getPosition(), c1.getRadius(), 
//         r1.getPosition(), r1.getHalfWidth(), r1.getHalfHeight())) 
//     {
//         c1.setColliding(true);
//         r1.setColliding(true);
//     }
// }

// /*
//     COLLISION CHECKING
// */

// //check for two circle collision
// bool Collision::isCCCollision(CircPlayer& c1, CircPlayer& c2) {
    
//     sf::Vector2f c1Pos = c1.getPosition();
//     sf::Vector2f c2Pos = c2.getPosition();

//     float distX = c1Pos.x - c2Pos.x;
//     float distY = c1Pos.y - c2Pos.y;
//     float distanceSquared = (distX*distX) + (distY*distY);

//     if (distanceSquared <= pow(c1.getRadius() + c2.getRadius(), 2)) {
//         return true;
//     }
//     return false;
// }

// bool Collision::isCCCollision(sf::Vector2f c1Pos, float c1Radius, sf::Vector2f c2Pos, float c2Radius) {

//     float distX = c1Pos.x - c2Pos.x;
//     float distY = c1Pos.y - c2Pos.y;
//     float distanceSquared = (distX*distX) + (distY*distY);

//     if (distanceSquared <= pow(c1Radius + c2Radius, 2)) {
//         return true;
//     }
//     return false;
// }

// //check for two rectangle collision
// bool Collision::isAABBCollision(RectPlayer* r1, RectPlayer* r2) 
// {
//     //<----------------- CHECK FOR COLLISION -----------------> 
//     //get current and prev position of the first rectangle
//     sf::Vector2f r1Pos = r1->getPosition();
//     sf::Vector2f r1prevPos = r1->getPrevPosition();

//     //get the position of the rectangle you want to check the collision against
//     sf::Vector2f r2Pos = r2->getPosition();

//     //obtain the overlap rectangle 
//     sf::Vector2f delta = sf::Vector2f(r1Pos.x-r2Pos.x,r1Pos.y-r2Pos.y);
//     //get the absolute value of this
//     sf::Vector2f deltaAbs = sf::Vector2f(abs(delta.x),abs(delta.y));

//     //take the absolute value away from the today height and total width
//     //<------------------------><----------> total width
//     //<----------------------> the overlap
//     float ox = r1->getHalfWidth() + r2->getHalfWidth() - deltaAbs.x;
//     float oy = r1->getHalfHeight() + r2->getHalfHeight() - deltaAbs.y;

//     //if the difference is negative in either then its not a collision
//     if (ox < 0 || oy < 0) {
//         return false;
//     }

//     //<----------------- RESOLVE THE COLLISION -----------------> 
//     bool wasLeft = r1prevPos.x + r1->getHalfWidth() <= r2Pos.x - r2->getHalfWidth();
//     bool wasRight = r1prevPos.x - r1->getHalfWidth() >= r2Pos.x + r2->getHalfWidth();

//     bool wasAbove = r1prevPos.y + r1->getHalfHeight() <= r2Pos.y - r2->getHalfHeight();
//     bool wasBelow = r1prevPos.y - r1->getHalfHeight() >= r2Pos.y + r2->getHalfHeight();

//     if (wasLeft || wasRight) {
//         if (wasAbove) { 
//             std::cout << "above and left" << std::endl;
//             r1->resolvePosition(0,-oy);
//             return true;
//         } else if (wasBelow) {
//             std::cout << "above and below" << std::endl;
//             r1->resolvePosition(0,oy);
//             return true;
//         } 
//     }
     
//     if (wasRight) {
//         std::cout << "right" << std::endl;
//         r1->resolvePosition(ox,0);
//     } else if (wasLeft) {
//         std::cout << "left" << std::endl;
//         r1->resolvePosition(-ox,0);
//     } else if (wasAbove) {
//         std::cout << "up" << std::endl;
//         r1->resolvePosition(0,-oy);
//     } else if (wasBelow) {
//         std::cout << "down" << std::endl;
//         r1->resolvePosition(0,oy);
//     }

//     return true;
// }

// void Collision::resolvePosition(RectPlayer* rectangle, float deltax, float deltay, float absx, float absy) {
//     if (absx > absy) {
//         rectangle->resolvePosition(deltax,0);
//     } else {
//         rectangle->resolvePosition(0,deltay);
//     }
// }

// bool Collision::oldAABBCollision(RectPlayer& r1, RectPlayer& r2)  {

//     sf::Vector2f r1Pos = r1.getPosition();
//     sf::Vector2f r2Pos = r2.getPosition();

//     float r1Width = r1.getHalfWidth();
//     float r2Width = r2.getHalfWidth();

//     float r1Height = r1.getHalfHeight();
//     float r2Height = r2.getHalfHeight();

//     if (r1Pos.x + r1Width >= r2Pos.x - r2Width &&
//         r1Pos.x - r1Width <= r2Pos.x + r2Width &&
//         r1Pos.y + r1Height >= r2Pos.y - r2Height  &&
//         r1Pos.y - r1Height <= r2Pos.y + r2Height)
//     {                           
//         return true;
//     }
//     return false;
// };

// // bool Collision::isAABBCollision(sf::Vector2f r1Pos, float r1Width, float r1Height, sf::Vector2f r2Pos, float r2Width, float r2Height)  {

//     if (r1Pos.x + r1Width >= r2Pos.x - r2Width &&
//         r1Pos.x - r1Width <= r2Pos.x + r2Width &&
//         r1Pos.y + r1Height >= r2Pos.y - r2Height  &&
//         r1Pos.y - r1Height <= r2Pos.y + r2Height)
//     {                           
//         return true;
//     }
//     return false;
// };

// //check for circle vs rect collision
// bool Collision::isCircRectCollision(CircPlayer& c1, RectPlayer& r1) {
//     sf::Vector2f cPos = c1.getPosition();
//     sf::Vector2f rPos = r1.getPosition();
    
//     //get the distance the circle is away from the center of the rectangle
//     float xDistance = abs(cPos.x - rPos.x);
//     float yDistance = abs(cPos.y - rPos.y);

//     float rWidth = r1.getHalfWidth();
//     float rHeight = r1.getHalfHeight();
//     float cRadius = c1.getRadius();

//     //check the circles are within the circle radius away from the rectangle sides
//     //all circles that aren't colliding will hit these checks and return false
//     if (xDistance > (rWidth + cRadius)) { return false; }
//     if (yDistance > (rHeight + cRadius)) { return false; }

//     //for the normal cases against the faces of the rectangle
//     if (xDistance <= rWidth) { return true; } 
//     if (yDistance <= rHeight) { return true; }

//     //check that the circle overlaps any of the corners of the rectangle
//     float cDistSq = pow(xDistance - rWidth,2) + pow(yDistance - rHeight, 2);
//     return (cDistSq <= (cRadius*cRadius));
// }

// bool Collision::isCircRectCollision(sf::Vector2f cPos, float cRadius, sf::Vector2f rPos, float rHalfWidth, float rHalfHeight) 
// {
//     //get the distance the circle is away from the center of the rectangle
//     float xDistance = abs(cPos.x - rPos.x);
//     float yDistance = abs(cPos.y - rPos.y);

//     //check the circles are within the circle radius away from the rectangle sides
//     //all circles that aren't colliding will hit these checks and return false
//     if (xDistance > (rHalfWidth + cRadius)) { return false; }
//     if (yDistance > (rHalfHeight + cRadius)) { return false; }

//     //for the normal cases against the faces of the rectangle
//     if (xDistance <= (rHalfWidth)) { return true; } 
//     if (yDistance <= (rHalfHeight)) { return true; }

//     //check that the circle overlaps any of the corners of the rectangle
//     float cDistSq = pow(xDistance - rHalfWidth,2) + pow(yDistance - rHalfHeight, 2);
//     return (cDistSq <= (cRadius*cRadius));
// }