#include <iostream>
#include <memory>
#include "Expression.h"

int main() {
    std::cout << "=== Ejercicio 3: Composite - Expresiones Matematicas ===\n";

    // Representar: f(x) = (x^2 + 3*x) * sin(x)
    auto x= std::make_shared<Variable>();
    auto expr= std::make_shared<Multiply>(
        std::make_shared<Add>(
            std::make_shared<Power>(x, std::make_shared<Constant>(2)),
            std::make_shared<Multiply>(std::make_shared<Constant>(3), x)
        ),
        std::make_shared<Sin>(x)
    );

    auto deriv= expr->derivative();

    std::cout << "f(x)= " << expr->toString() << "\n";
    std::cout << "f'(x)= " << deriv->toString() << "\n";
    std::cout << "f(2)= " << expr->evaluate(2) << "\n";
    std::cout << "f'(2)= " << deriv->evaluate(2) << "\n";

    return 0;
}