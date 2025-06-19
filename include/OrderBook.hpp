#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <queue>
#include <map>
#include "Order.hpp"

class OrderBook {
    private:
        std::priority_queue<double> buyOrders; 
        std::priority_queue<double, std::vector<double>, std::greater<double>> sellOrders; 
        std::map<double, std::queue<Order>> buyOrderLevels; 
        std::map<double, std::queue<Order>> sellOrderLevels;
        
    public:
        void addOrder(const Order& order);
        bool isSellEmpty() const;
        bool isBuyEmpty() const;
        double getBestBuyPrice() const;
        double getBestSellPrice() const;
        void removeTopBuyOrder();
        void removeTopSellOrder();
};

#endif