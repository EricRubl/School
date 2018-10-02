//
// Created by Eric on 03.10.2018.
//

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_RANDOMIZER_HPP
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_RANDOMIZER_HPP

#include "Transaction.hpp"
#include "Account.hpp"

#include <vector>
#include <random>
#include <iostream>

namespace Lab1
{
    int generateRandomNumber(int low, int high)
    {
        auto time = std::time(nullptr);
        std::mt19937 gen(static_cast<unsigned int>(rand() + time));
        std::uniform_int_distribution<> uniformDistribution(low, high);

        return uniformDistribution(gen);
    }



    static const Transaction& generateRandomTransaction(const std::vector<Account>& accounts)
    {

    }
}

#endif //PARALLEL_AND_DISTRIBUTED_PROGRAMMING_RANDOMIZER_HPP
