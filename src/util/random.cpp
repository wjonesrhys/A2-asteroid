#include <random.hpp>

std::random_device Random::rd;

int Random::randomBinaryChoice() {
    return rd() * 2 / RAND_MAX;
}

float Random::randomHeight(sf::Vector2u windowSize, float ballRadius) {
    int randNum = rd() * 2 / RAND_MAX;
    
    //calculate the y component of screen vector to the corner - considering radius
    float yScreenComponent = (windowSize.y/2 - ballRadius/2) / (windowSize.x/2 - ballRadius);
    float randResult = rand() * yScreenComponent / RAND_MAX;

    return randNum == 0 ? randResult * -1 : randResult;
}

void Random::testingRandom() {
        /**
     * ------ TESTING RANDOM NUMBERS ------
     * rand dist seems good over large numbers (maybe too good) but not small (like 20)
     * rand is unusable because it differs over architecture
     * rd is good with small and large numbers (at least some error in 1000)
    */
    // testrandom();
    // std::cout << Random::randomBinaryChoice() << std::endl;

    for (int i=0; i<5; i++) {
        std::cout<< Random::randomBinaryChoice() << " ";
    }
    std::cout << "\n";

    for (int i=0; i<5; i++) {
        std::cout<< Random::randomHeight(sf::Vector2u(1000,1000), 10.0f) << " ";
    }
    std::cout << "\n";
}