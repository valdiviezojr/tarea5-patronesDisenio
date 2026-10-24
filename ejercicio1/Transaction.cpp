#include "Transaction.h"

#include <iomanip>
#include <sstream>
#include <utility>

Transaction::Transaction(std::size_t id,
                         TransactionType type,
                         std::string accountId,
                         double amount)
    : id_(id), type_(type), accountId_(std::move(accountId)), amount_(amount) {}

std::size_t Transaction::getId() const {
    return id_;
}

TransactionType Transaction::getType() const {
    return type_;
}

const std::string& Transaction::getAccountId() const {
    return accountId_;
}

double Transaction::getAmount() const {
    return amount_;
}

std::string Transaction::getTypeName() const {
    return type_ == TransactionType::Deposit ? "deposit" : "withdraw";
}

std::string Transaction::toString() const {
    std::ostringstream out;
    out << '#' << id_ << ' ' << getTypeName() << ' '
        << std::fixed << std::setprecision(2) << amount_
        << " account=" << accountId_;
    return out.str();
}
