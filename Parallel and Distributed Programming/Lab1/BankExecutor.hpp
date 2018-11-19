#include <utility>

//
// Created by Eric on 10.10.2018.
//

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_BANKEXECUTOR_HPP
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_BANKEXECUTOR_HPP

#include "Account.hpp"
#include "Randomizer.hpp"

#include <vector>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <shared_mutex>

namespace Lab1
{
    class BankExecutor
    {
    private:
        unsigned short threadCount;
        unsigned short accountCount;
        unsigned long long transactionCount;
        bool finished;
        std::chrono::seconds batchTimeSpan;
        std::vector<Account> accounts;
        std::shared_mutex accountsMutex;
        std::vector<std::thread> threads;

    public:
        BankExecutor() = default;

        BankExecutor(const BankExecutor &other) = default;

        BankExecutor(unsigned short threadCount, unsigned short accountCount, unsigned long long transactionCount,
                     const std::chrono::seconds &batchTimeSpan) : threadCount(threadCount), accountCount(accountCount),
                    transactionCount(transactionCount), batchTimeSpan(batchTimeSpan), accounts(), accountsMutex(),
                    finished(false)
        {
            if(threadCount < 1 or accountCount < 2 or transactionCount < 1 or batchTimeSpan < std::chrono::seconds(1))
                throw "BankExecutor initialised with invalid parameters!\n";

            auto start = std::chrono::high_resolution_clock::now();

            for(unsigned short id = 0; id < accountCount; ++id)
                accounts.push_back(Account(id, (long long) Lab1::generateRandomNumber(0, 10000)));

            auto finish = std::chrono::high_resolution_clock::now();

            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

            std::cout << "Generated " << accountCount << " accounts in " << elapsed.count() << " milliseconds\n";
        }

        ~BankExecutor() = default;

        void stopAndCheck()
        {
            try
            {
                while(not finished)
                {
                    std::this_thread::sleep_for(batchTimeSpan);

                    std::cout << "Stopping all threads for checking!\n";

                    accountsMutex.lock();

                    for(const auto &account : accounts)
                    {
                        if(not account.isValid())
                        {
                            std::string exceptionMessage = "Account ";
                            exceptionMessage += std::to_string(account.getId());
                            exceptionMessage += " is not valid!\n";

                            throw exceptionMessage.c_str();
                        }
                    }

                    std::cout << "Check OK\n";

                    accountsMutex.unlock();
                }
            }
            catch(char const* ex)
            {
                std::cerr << ex;
            }
        }

        void transactioner(unsigned long long transactions)
        {
            try
            {
                for(auto i = 0; i < transactions; ++i)
                {
                    accountsMutex.lock_shared();

                    auto amount = (unsigned short)Lab1::generateRandomNumber(0, 10);

                    auto from = (unsigned short)Lab1::generateRandomNumber(0, accountCount - 1);

                    accounts[from].lock();

                    unsigned short to;

                    int lockedStatus;

                    do
                    {
                        to = (unsigned short)Lab1::generateRandomNumber(0, accountCount - 1);

                        lockedStatus = accounts[to].try_lock();
                    } while(from == to and lockedStatus not_eq -1);

                    auto transaction = Transaction(from, to, amount);

                    accounts[from].addTransaction(transaction);

                    accounts[to].addTransaction(transaction);

                    accounts[from].unlock();

                    accounts[to].unlock();

                    accountsMutex.unlock_shared();
                }
            }
            catch (char const* ex)
            {
                std::cerr << ex;
            }
        }

        void start()
        {
            unsigned long long transactionsPerThread = transactionCount / threadCount;

            std::cout << "Creating " << threadCount << " threads to perform " << transactionsPerThread << " transactions each\n";

            auto start = std::chrono::high_resolution_clock::now();

            for(unsigned short id = 0; id < threadCount; ++id)
                threads.push_back(std::thread(&BankExecutor::transactioner, this, transactionsPerThread));

            auto integrityChecker = std::thread(&BankExecutor::stopAndCheck, this);

            std::cout << "Created integrity checker thread\n";

            for(auto& thread : threads)
                thread.join();

            auto finish = std::chrono::high_resolution_clock::now();

            this->finished = true;

            integrityChecker.join();

            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

            std::cout << "Transacting took " << elapsed.count() << " milliseconds\n";
        }
    };
}

#endif //PARALLEL_AND_DISTRIBUTED_PROGRAMMING_BANKEXECUTOR_HPP
