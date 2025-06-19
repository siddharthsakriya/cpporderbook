#include "OrderBook.hpp"

void OrderBook::addOrder(const Order& order) {
    if (order.getSide() == OrderSide::BUY) {
        if (buyOrderLevels.count(order.getPrice()) == 0) {
            buyOrders.push(order.getPrice());
            buyOrderLevels[order.getPrice()] = std::queue<Order>();
        }
        buyOrderLevels[order.getPrice()].push(order);
        
    } else {
        if (sellOrderLevels.count(order.getPrice()) == 0) {
            sellOrders.push(order.getPrice());
            sellOrderLevels[order.getPrice()] = std::queue<Order>();
        }
        sellOrderLevels[order.getPrice()].push(order);       
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
    