#ifndef ORDER_HPP
#define ORDER_HPP

#include "OrderSide.hpp"

class Order {
    private:
        int orderId;
        long volume;
        double price;
        OrderSide side;

    public:
        Order(int id, double vol, double pr, OrderSide s)
            : orderId(id), volume(vol), price(pr), side(s) {}

        virtual ~Order() = default;

        int getOrderId() const { return orderId; }
        double getVolume() const { return volume; }
        OrderSide getSide() const { return side; }
        double getPrice() const { return price; }

        virtual void accept(class OrderVisitor& visitor) const = 0;
};

#endif 