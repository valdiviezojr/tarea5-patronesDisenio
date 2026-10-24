#pragma once

#include <mutex>
#include <string>

class TransactionManager;

class Account {
public:
    Account(std::string id, double initialBalance);

    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;

    std::string getId() const;
    double getBalance() const;

private:
    friend class TransactionManager;

    bool applyDeposit(double amount);
    bool applyWithdraw(double amount);

    mutable std::mutex mutex_;
    std::string id_;
    double balance_;
};
