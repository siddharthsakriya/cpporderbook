#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <queue>
#include <map>
#include <vector>
#include <memory>
#include <iostream>

#include "Order.hpp"

class OrderBook {
    private:
        std::priority_queue<double> buyOrders; 
        std::priority_queue<double, std::vector<double>, std::greater<double>> sellOrders;

        std::map<double, std::queue<std::shared_ptr<Order>>> buyOrderLevels; 
        std::map<double, std::queue<std::shared_ptr<Order>>> sellOrderLevels;
        
    public:
        void addOrder(std::shared_ptr<Order> order);

        bool isSellEmpty() const;
        bool isBuyEmpty() const;
        double getBestBuyPrice() const;
        double getBestSellPrice() const;
        std::shared_ptr<Order> showTopBuyOrder(double price);
        std::shared_ptr<Order> showTopSellOrder(double price);
        void removeTopBuyOrder();
        void removeTopSellOrder();
        void printOrderBook();

};

#endif