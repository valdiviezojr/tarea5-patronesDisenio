#include "TransactionManager.h"

TransactionManager& TransactionManager::getInstance() {
    static TransactionManager instance;
    return instance;
}

bool TransactionManager::deposit(Account* account, double amount) {
    return apply(account, TransactionType::Deposit, amount);
}

bool TransactionManager::withdraw(Account* account, double amount) {
    return apply(account, TransactionType::Withdraw, amount);
}

std::vector<Transaction> TransactionManager::getHistory() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return history_;
}

std::size_t TransactionManager::getOperationCount() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return history_.size();
}

bool TransactionManager::apply(Account* account, TransactionType type, double amount) {
    if (account == nullptr || amount <= 0.0) {
        return false;
    }

    std::lock_guard<std::mutex> lock(mutex_);
    const bool applied = type == TransactionType::Deposit
        ? account->applyDeposit(amount)
        : account->applyWithdraw(amount);

    if (applied) {
        history_.emplace_back(nextTransactionId_++, type, account->getId(), amount);
    }
    return applied;
}
