#ifndef ORDER_HPP
#define ORDER_HPP

#include "OrderSide.hpp"
#include "OrderType.hpp"

class Order {
    private:
        int orderId;
        long volume;
        double price; // Assuming price is needed for matching
        OrderSide side;
        OrderType type;

    public:
        Order(int id, double vol, double pr, OrderSide s, OrderType t)
            : orderId(id), volume(vol), price(pr), side(s), type(t) {}

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

        double getPrice() const {
            return price;
        }
};

#endif 