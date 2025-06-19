#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <queue>
#include <map>
#include "Order.hpp"

class OrderBook {
    private:
        std::priority_queue<double> buyOrders; 
        std::priority_queue<double> sellOrders; 
        std::map<double, std::queue<Order>> buyOrderLevels; 
        std::map<double, std::queue<Order>> sellOrderLevels;
        
    public:
        void addOrder(const Order& order);
        void isSellEmpty() const;
        void isBuyEmpty() const;
        void getBestBuyPrice() const;
        void getBestSellPrice() const;
        void removeTopBuyOrder();
        void removeTopSellOrder();
};

#endif