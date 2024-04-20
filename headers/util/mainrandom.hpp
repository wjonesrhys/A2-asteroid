#include <iostream>
#include <vector>
#include <random>

int returnChoice(int randNum) {
    return randNum == 0 ? -1 : 1;
}

int rand_rd() {
    std::random_device rd;
    int randNum = (rd() * 2) / RAND_MAX;
    return returnChoice(randNum);
}

int rand_gen() {
    int randNum = (rand() * 2) / RAND_MAX;
    return returnChoice(randNum);
}

int rand_dist1(std::default_random_engine generator, std::uniform_int_distribution<int> distribution) {
    return returnChoice(distribution(generator));
}

std::vector<int> rand_dist() {
    std::vector<int> directions_dist;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1);

    for (int i=0; i<1000; i++) {
        directions_dist.push_back(returnChoice(distribution(generator)));
    }
    return directions_dist;
}

void printResults(std::vector<int> vecOfOnes, std::string name) {
    int left = 0;
    int right = 0;
    for (int result : vecOfOnes) {
        result == 1 ? left++ : right++;
    }
    std::cout << name << ": " << std::endl;
    std::cout << "number left: " << left << std::endl;
    std::cout << "number right: " << right << std::endl;
}

void testrandom() {
    srand(time(nullptr));

    std::vector<int> directions_rand;
    for (int i=0; i<1000; i++) {
        directions_rand.push_back(rand_gen());
    }
    
    std::vector<int> directions_dist = rand_dist();

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1);
    std::vector<int> directions_dist1;
    for (int i=0; i<1000; i++) {
        directions_dist1.push_back(rand_dist1(generator,distribution));
    }

    std::vector<int> directions_rd;
    for (int i=0; i<1000; i++) {
        directions_rd.push_back(rand_rd());
    }

    printResults(directions_rand, "rand");
    printResults(directions_dist, "dist (without passing args)");
    printResults(directions_dist1, "dist (with passing args)");
    printResults(directions_rd, "rd");
}