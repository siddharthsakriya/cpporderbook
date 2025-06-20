#ifndef LIMITORDER_HPP
#define LIMITORDER_HPP

#include "Order.hpp"
#include "OrderVisitor.hpp"

class LimitOrder : public Order {
public:
    using Order::Order; 

    void accept(OrderVisitor& visitor) const override {
        visitor.visit(*this); 
    }
};

#endif