#include <algorithm>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

#include "Account.h"
#include "TransactionManager.h"

namespace {

constexpr int kThreads = 10;
constexpr double kInitialBalance = 1000.0;
constexpr double kDepositAmount = 100.0;
constexpr double kWithdrawAmount = 50.0;

}

int main() {
    std::cout << "=== Ejercicio 1: Singleton TransactionManager ===\n";

    auto& manager = TransactionManager::getInstance();
    Account account("A1", kInitialBalance);
    std::vector<std::thread> threads;
    std::vector<const TransactionManager*> addresses(kThreads, nullptr);
    threads.reserve(kThreads);

    for (int i = 0; i < kThreads; ++i) {
        threads.emplace_back([&manager, &account, &addresses, i]() {
            addresses[i] = &TransactionManager::getInstance();
            manager.deposit(&account, kDepositAmount);
            manager.withdraw(&account, kWithdrawAmount);
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    const double expected = kInitialBalance + kThreads * (kDepositAmount - kWithdrawAmount);
    const bool uniqueAddress = std::all_of(
        addresses.begin(),
        addresses.end(),
        [&manager](const TransactionManager* address) { return address == &manager; });
    const bool balanceOk = std::abs(account.getBalance() - expected) < 1e-9;

    std::cout << "Balance final: " << account.getBalance() << '\n';
    std::cout << "Balance esperado (1000 + 10*100 - 10*50): " << expected << '\n';
    std::cout << "Direccion manager: " << &TransactionManager::getInstance() << '\n';
    std::cout << "Direccion unica: " << (uniqueAddress ? "si" : "no") << '\n';
    std::cout << "Operaciones registradas: " << manager.getOperationCount() << '\n';
    std::cout << "Validacion de balance: " << (balanceOk ? "OK" : "FALLO") << '\n';

    return 0;
}
