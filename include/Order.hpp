#ifndef ORDER_HPP
#define ORDER_HPP

#include "OrderSide.hpp"
#include "OrderType.hpp"

class Order {
    private:
        int orderId;
        double volume;
        OrderSide side;
        OrderType type;

    public:
        Order(int id, double vol, OrderSide s, OrderType t)
            : orderId(id), volume(vol), side(s), type(t) {}

        int getOrderId() const {
            return orderId;
        }

        double getVolume() const {
            return volume;
        }

        OrderSide getSide() const {
            return side;
        }

        OrderType getType() const {
            return type;
        }
};

#endif 