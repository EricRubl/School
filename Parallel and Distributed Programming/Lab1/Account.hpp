
#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP

#include <vector>
#include <utility>
#include "Transaction.hpp"

namespace Lab1
{
    class Account
    {
    private:
        unsigned long long balance;
        std::vector<Transaction> transactions;

    public:
        Account() : balance(), transactions()
        {};

        Account(const Account& other) : balance(other.getBalance()), transactions(other.getTransactions())
        {};

        explicit Account(const unsigned long long& balance) : balance(balance), transactions()
        {};

        Account(const unsigned long long& balance, std::vector<Transaction> transactions) : balance(balance),
                transactions(std::move(transactions))
        {};

        ~Account() = default;

        unsigned long long int getBalance() const
        {
            return balance;
        }

        const std::vector<Transaction>& getTransactions() const
        {
            return transactions;
        }

        Account& operator+=(const int& value)
        {
            this->balance += value;
            return *this;
        }

        Account& operator-=(const int& value)
        {
            this->balance -= value;
            return *this;
        }

        Account& operator++()
        {
            ++(this->balance);
            return *this;
        }

        const Account operator++(int)
        {
            Account old = *this;
            ++(*this);
            return old;
        }

        Account& operator--()
        {
            --(this->balance);
            return *this;
        }

        const Account operator--(int)
        {
            Account old = *this;
            --(*this);
            return old;
        }

        void addTransaction(const Transaction& transaction)
        {
            this->transactions.push_back(transaction);
        }
    };
}

#endif //PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP