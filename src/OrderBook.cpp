#include "OrderBook.hpp"

void OrderBook::addOrder(std::shared_ptr<Order> order) {
    double price = order->getPrice();   
    
    if (order->getSide() == OrderSide::BUY) {
        if(buyOrderLevels.count(price) == 0) {
            buyOrders.push(price);
            buyOrderLevels[price] = std::queue<std::shared_ptr<Order>>();
        }
        buyOrderLevels[price].push(order);
    }
    else if (order->getSide() == OrderSide::SELL) {
        if(sellOrderLevels.count(price) == 0) {
            sellOrders.push(price);
            sellOrderLevels[price] = std::queue<std::shared_ptr<Order>>();
        }
        sellOrderLevels[price].push(order);
    }
    else {
        throw std::invalid_argument("Invalid order side");
    }
}

bool OrderBook::isSellEmpty() const {
    return sellOrders.empty();
}

bool OrderBook::isBuyEmpty() const {
    return buyOrders.empty();
}

double OrderBook::getBestBuyPrice() const {
    if (buyOrders.empty()) {
        return 0.0; 
    }
    return buyOrders.top();
}

double OrderBook::getBestSellPrice() const {
    if (sellOrders.empty()) {
        return 0.0; 
    }
    return sellOrders.top();
}

void OrderBook::removeTopBuyOrder() {
    if (!buyOrders.empty()) {
        double bestPrice = buyOrders.top();
        buyOrderLevels[bestPrice].pop();
        if (buyOrderLevels[bestPrice].empty()) {
            buyOrderLevels.erase(bestPrice);
            buyOrders.pop();
        }
    }
}

void OrderBook::removeTopSellOrder() {
    if (!sellOrders.empty()) {
        double bestPrice = sellOrders.top();
        sellOrderLevels[bestPrice].pop();
        if (sellOrderLevels[bestPrice].empty()) {
            sellOrderLevels.erase(bestPrice);
            sellOrders.pop();
        }
    }   
}
    