#include "Lab1/BankExecutor.hpp"

#include <iostream>

int main()
{
    try
    {
        for(unsigned short threadCount = 1; threadCount <= 4; ++threadCount)
        {
            auto bankExecutor = Lab1::BankExecutor(threadCount, 60000, 1000000, std::chrono::seconds(5));
            bankExecutor.start();
        }
    }
    catch(char const* exception)
    {
        std::cerr << exception << '\n';
    }

    return 0;
}   