#include "Account.h"

#include <utility>

Account::Account(std::string id, double initialBalance)
    : id_(std::move(id)), balance_(initialBalance) {}

std::string Account::getId() const {
    return id_;
}

double Account::getBalance() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return balance_;
}

bool Account::applyDeposit(double amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    balance_ += amount;
    return true;
}

bool Account::applyWithdraw(double amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (balance_ < amount) {
        return false;
    }
    balance_ -= amount;
    return true;
}
