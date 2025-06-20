#ifndef ORDERVISITOR_HPP
#define ORDERVISITOR_HPP

#include "Order.hpp"

class LimitOrder;
class MarketOrder;

class OrderVisitor {
public:
    virtual void visit(const LimitOrder& order) = 0;
    virtual void visit(const MarketOrder& order) = 0;
    virtual ~OrderVisitor() = default;
};

#endif