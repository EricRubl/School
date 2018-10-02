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
    using TransactionID = std::pair<unsigned short int, unsigned short int>;

    class Transaction
    {
    private:
        TransactionID id;
        unsigned short int from;
        unsigned short int to;
        unsigned short int amount;
        std::chrono::milliseconds duration;
    public:
        Transaction() : id(), from(), to(), amount(), duration()
        {};

        Transaction(const Transaction& other) : id(other.getId()), from(other.getFrom()), to(other.getTo()),
                amount(other.getAmount()), duration(other.getDuration())
        {};

        Transaction(TransactionID id, const unsigned short int& from, const unsigned short int& to,
                    const unsigned short int& amount, const std::chrono::milliseconds duration) : id(std::move(id)),
                    from(from), to(to), amount(amount), duration(duration)
        {
            if(id.first < 0 || id.second < 0 || from < 0 || to < 0 || amount < 0 || duration.count() < 0)
                throw "Transaction initialised with invalid parameters!";
        };

        ~Transaction() = default;


        TransactionID getId() const
        {
            return id;
        }

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

        void setDuration(const std::chrono::milliseconds& duration)
        {
            this->duration = duration;
        }

        const std::chrono::milliseconds& getDuration() const
        {
            return duration;
        }

        friend std::ostream& operator<<(std::ostream& output, const Transaction& transaction)
        {
            std::string print;

            print = "Thread ";
            print += std::to_string(transaction.id.second);
            print += " | ";
            print += std::to_string(transaction.from);
            print += " --> ";
            print += std::to_string(transaction.amount);
            print += "$ --> ";
            print += std::to_string(transaction.to);
            print += " | ";
            print += std::to_string(transaction.duration.count());
            print += "ms\n";

            output << print;

            return output;
        }
    };
}

#endif //PARALLEL_AND_DISTRIBUTED_PROGRAMMING_TRANSACTION_HPP