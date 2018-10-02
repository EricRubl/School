//
// Created by Eric on 02.10.2018.
//

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_ACCOUNT_HPP

#include "Transaction.hpp"

#include <vector>
#include <utility>
#include <ostream>

namespace Lab1
{
    class Account
    {
    private:
        unsigned short int id;
        unsigned long long balance;
        std::vector<Transaction> transactions;

    public:
        Account() : id(), balance(), transactions()
        {};

        Account(const Account& other) : id(other.getId()), balance(other.getBalance()), transactions(
                other.getTransactions())
        {};

        explicit Account(const unsigned short int& id, const unsigned long long& balance) : id(id), balance(balance),
                transactions()
        {
            if(balance < 0)
                throw "Account initialised with invalid parameters!";
        };

        Account(const unsigned short int& id, const unsigned long long& balance, std::vector<Transaction> transactions)
                : id(id), balance(balance), transactions(std::move(transactions))
        {
            if(balance < 0)
                throw "Account initialised with invalid parameters!";
        };

        ~Account() = default;

        unsigned short int getId() const
        {
            return id;
        }

        unsigned long long int getBalance() const
        {
            return balance;
        }

        const std::vector<Transaction>& getTransactions() const
        {
            return transactions;
        }

        void addTransaction(const Transaction& transaction) noexcept
        {
            this->transactions.push_back(transaction);
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

        friend std::ostream& operator<<(std::ostream& output, const Account& account)
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