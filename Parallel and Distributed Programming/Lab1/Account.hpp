//
// Created by Eric on 02.10.2018.
//

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP

#include "Transaction.hpp"

#include <vector>
#include <utility>
#include <ostream>
#include <mutex>

namespace Lab1
{
    class Account
    {
    private:
        unsigned short id;
        long long balance;
        long long initialBalance;
        std::vector<Transaction> transactions;
        std::mutex mutex;

    public:
        Account() : id(), balance(), initialBalance(), transactions(), mutex()
        {}

        Account(const Account& other) : id(other.id), balance(other.balance), initialBalance(other.initialBalance),
                transactions(other.transactions), mutex()
        {}

        Account(const unsigned short &id, const long long &initialBalance) : id(id),
                balance(initialBalance), transactions(), initialBalance(initialBalance), mutex()
        {}

        ~Account() = default;

        unsigned short getId() const
        {
            return id;
        };

        void lock()
        {
            return mutex.lock();
        }

        void unlock()
        {
            mutex.unlock();
        }

        int try_lock()
        {
            return mutex.try_lock();
        }

        void addTransaction(const Transaction &transaction)
        {
            if(transaction.getFrom() == id)
                balance -= transaction.getAmount();
            else if(transaction.getTo() == id)
                balance += transaction.getAmount();

            transactions.push_back(transaction);
        }

        bool isValid() const
        {
            auto expectedBalance = initialBalance;

            for(const auto &transaction : transactions)
                if(transaction.getFrom() == id)
                    expectedBalance -= transaction.getAmount();
                else
                    expectedBalance += transaction.getAmount();

            return expectedBalance == balance;
        }

        friend std::ostream &operator<<(std::ostream &output, const Account &account)
        {
            std::string print;

            print = std::to_string(account.id);
            print += " | ";
            print += std::to_string(account.balance);
            print += "$\n";

            output << print;

            return output;
        }
    };
}

#endif //PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP