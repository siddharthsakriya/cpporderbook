#ifndef FOKORDER_HPP
#define FOKORDER_HPP

#include "Order.hpp"
#include "OrderVisitor.hpp"

class FokOrder : public Order {
public:
    using Order::Order; 

    void accept(OrderVisitor& visitor) const override;
};

#endif