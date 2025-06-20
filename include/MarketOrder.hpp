#ifndef MARKETORDER_HPP
#define MARKETORDER_HPP

#include "Order.hpp"
#include "OrderVisitor.hpp"

class MarketOrder : public Order {
public:
    using Order::Order; 

    void accept(OrderVisitor& visitor) const override {
        visitor.visit(*this); 
    }
};

#endif