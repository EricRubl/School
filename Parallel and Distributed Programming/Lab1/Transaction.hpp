//
// Created by Eric on 02.10.2018.
//

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_TRANSACTION_HPP
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_TRANSACTION_HPP

#include <chrono>
#include <utility>
#include <ostream>
#include <thread>

namespace Lab1
{
    class Transaction
    {
    private:
        unsigned short from;
        unsigned short to;
        unsigned short amount;

    public:
        Transaction() = default;

        Transaction(const Transaction& other) = default;

        Transaction(const unsigned short& from, const unsigned short& to,
                    const unsigned short& amount) : from(from), to(to), amount(amount)
        {
            if(from == to or from < 0 or to < 0 or amount < 0)
                throw "Transaction initialised with invalid parameters!\n";
        };

        ~Transaction() = default;

        unsigned short getFrom() const
        {
            return from;
        }

        unsigned short getTo() const
        {
            return to;
        }

        unsigned short getAmount() const
        {
            return amount;
        }

        friend std::ostream& operator<<(std::ostream& output, const Transaction& transaction)
        {
            std::string print;

            print = std::to_string(transaction.from);
            print += " --> ";
            print += std::to_string(transaction.amount);
            print += "$ --> ";
            print += std::to_string(transaction.to);
            print += "\n";

            output << print;

            return output;
        }
    };
}

#endif //PARALLEL_AND_DISTRIBUTED_PROGRAMMING_TRANSACTION_HPP