#ifndef PATRONESDISENIO_EXPRESSION_H
#define PATRONESDISENIO_EXPRESSION_H

#pragma once

#include <memory>
#include <string>
#include <cmath>

//Interfaz base Expression
class Expression {
public:
    virtual ~Expression()= default;
    virtual double evaluate(double x) const= 0;
    virtual std::shared_ptr<Expression> derivative() const= 0;
    virtual std::string toString() const= 0;
};

//Hojas

class Constant final : public Expression {
public:
    explicit Constant(double value);
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
    double getValue() const;

private:
    double value_;
};

class Variable final : public Expression {
public:
    Variable()= default;
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

//Composite

class BinaryOperation: public Expression {
public:
    BinaryOperation(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

protected:
    std::shared_ptr<Expression> left_;
    std::shared_ptr<Expression> right_;
};

class Add final: public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

class Multiply final: public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

class Power final: public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

class UnaryFunction: public Expression {
public:
    explicit UnaryFunction(std::shared_ptr<Expression> argument);

protected:
    std::shared_ptr<Expression> argument_;
};

class Sin final: public UnaryFunction {
public:
    using UnaryFunction::UnaryFunction;
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

class Cos final: public UnaryFunction {
public:
    using UnaryFunction::UnaryFunction;
    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

#endif //PATRONESDISENIO_EXPRESSION_H