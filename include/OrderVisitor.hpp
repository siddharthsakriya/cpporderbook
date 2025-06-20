#ifndef ORDERVISITOR_HPP
#define ORDERVISITOR_HPP

#include "Order.hpp"

class LimitOrder;
class FokOrder;

class OrderVisitor {
public:
    virtual ~OrderVisitor() = default;
    virtual void visit(const LimitOrder& order) = 0;
    virtual void visit(const FokOrder& order) = 0;
};

#endif