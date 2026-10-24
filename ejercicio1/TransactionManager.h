#pragma once

#include <cstddef>
#include <mutex>
#include <vector>

#include "Account.h"
#include "Transaction.h"

class TransactionManager {
public:
    static TransactionManager& getInstance();

    TransactionManager(const TransactionManager&) = delete;
    TransactionManager& operator=(const TransactionManager&) = delete;
    TransactionManager(TransactionManager&&) = delete;
    TransactionManager& operator=(TransactionManager&&) = delete;

    bool deposit(Account* account, double amount);
    bool withdraw(Account* account, double amount);

    std::vector<Transaction> getHistory() const;
    std::size_t getOperationCount() const;

private:
    TransactionManager() = default;

    bool apply(Account* account, TransactionType type, double amount);

    mutable std::mutex mutex_;
    std::vector<Transaction> history_;
    std::size_t nextTransactionId_ = 1;
};
