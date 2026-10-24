#include "Expression.h"
#include <sstream>
#include <iomanip>

namespace {
std::string formatNumber(double val) {
    if (std::floor(val)== val) {
        return std::to_string(static_cast<long long>(val));
    }
    std::ostringstream ss;
    ss<< val;
    return ss.str();
}
}

Constant::Constant(double value) : value_(value) {}

double Constant::evaluate(double /*x*/) const {
    return value_;
}

std::shared_ptr<Expression> Constant::derivative() const {
    return std::make_shared<Constant>(0.0);
}

std::string Constant::toString() const {
    return formatNumber(value_);
}

double Constant::getValue() const {
    return value_;
}

double Variable::evaluate(double x) const {
    return x;
}

std::shared_ptr<Expression> Variable::derivative() const {
    return std::make_shared<Constant>(1.0);
}

std::string Variable::toString() const {
    return "x";
}

//BinaryOperation Base
BinaryOperation::BinaryOperation(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
    : left_(std::move(left)), right_(std::move(right)) {}

// (u + v)' = u' + v'
double Add::evaluate(double x) const {
    return left_->evaluate(x) + right_->evaluate(x);
}

std::shared_ptr<Expression> Add::derivative() const {
    return std::make_shared<Add>(left_->derivative(), right_->derivative());
}

std::string Add::toString() const {
    return "("+ left_->toString()+" + "+ right_->toString()+ ")";
}

//(u * v)' = u' * v + u * v'
double Multiply::evaluate(double x) const {
    return left_->evaluate(x) * right_->evaluate(x);
}

std::shared_ptr<Expression> Multiply::derivative() const {
    auto term1= std::make_shared<Multiply>(left_->derivative(), right_);
    auto term2= std::make_shared<Multiply>(left_, right_->derivative());
    return std::make_shared<Add>(term1, term2);
}

std::string Multiply::toString() const {
    return "("+ left_->toString()+" * "+ right_->toString()+ ")";
}

//Power: (u ^ n)' = n * u^(n - 1) * u' (asumiendo exponente constante real)
double Power::evaluate(double x) const {
    return std::pow(left_->evaluate(x), right_->evaluate(x));
}

std::shared_ptr<Expression> Power::derivative() const {
    double exponent= right_->evaluate(0.0);
    auto newExponent= std::make_shared<Constant>(exponent- 1.0);
    auto powerTerm= std::make_shared<Power>(left_, newExponent);
    auto coeffTerm= std::make_shared<Multiply>(right_, powerTerm);
    return std::make_shared<Multiply>(coeffTerm, left_->derivative());
}

std::string Power::toString() const {
    return "("+ left_->toString()+ "^"+ right_->toString()+ ")";
}

//UnaryFunction Base
UnaryFunction::UnaryFunction(std::shared_ptr<Expression> argument): argument_(std::move(argument)) {}

//Sin: (sin(u))' = cos(u) * u'
double Sin::evaluate(double x) const {
    return std::sin(argument_->evaluate(x));
}

std::shared_ptr<Expression> Sin::derivative() const {
    auto cosTerm= std::make_shared<Cos>(argument_);
    return std::make_shared<Multiply>(cosTerm, argument_->derivative());
}

std::string Sin::toString() const {
    return "sin("+ argument_->toString()+ ")";
}

//Cos: (cos(u))' = -1 * sin(u) * u'
double Cos::evaluate(double x) const {
    return std::cos(argument_->evaluate(x));
}

std::shared_ptr<Expression> Cos::derivative() const {
    auto negOne= std::make_shared<Constant>(-1.0);
    auto sinTerm= std::make_shared<Sin>(argument_);
    auto negSin= std::make_shared<Multiply>(negOne, sinTerm);
    return std::make_shared<Multiply>(negSin, argument_->derivative());
}

std::string Cos::toString() const {
    return "cos("+ argument_->toString()+ ")";
}