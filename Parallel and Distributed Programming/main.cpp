#include "Lab1/Randomizer.hpp"

#include <iostream>

int main()
{
    std::random_device rd;
    std::cout << rd.entropy() << '\n';
    for(int i = 0; i < 5; ++i)

        std::cout << Lab1::generateRandomNumber(17, 66) << std::endl;

    return 0;
}   