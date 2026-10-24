#pragma once

#include <cstddef>
#include <string>

enum class TransactionType {
    Deposit,
    Withdraw
};

class Transaction {
public:
    Transaction(std::size_t id, TransactionType type, std::string accountId, double amount);

    std::size_t getId() const;
    TransactionType getType() const;
    const std::string& getAccountId() const;
    double getAmount() const;
    std::string getTypeName() const;
    std::string toString() const;

private:
    std::size_t id_;
    TransactionType type_;
    std::string accountId_;
    double amount_;
};
