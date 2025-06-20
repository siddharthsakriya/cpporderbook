#include "MatchingEngine.hpp"
#include <iostream>
#include <memory>
#include "LimitOrder.hpp"
#include "FokOrder.hpp"

void MatchingEngine::visit(const LimitOrder& order) {
    double price = order.getPrice();
    long quantity = order.getVolume();

    if (order.getSide() == OrderSide::BUY) {
        while (quantity > 0 && !orderBook.isSellEmpty()){
            double best_price = orderBook.getBestSellPrice();
            
            if (best_price > price) {
                break;
            }

            std::shared_ptr<Order> best_order = orderBook.showTopSellOrder(best_price);
            
            if (!best_order) {
                continue;
            }

            long best_quantity = best_order->getVolume();
            long difference = best_quantity - quantity;

            if (difference >= 0) {                
                best_order->setVolume(difference);
                quantity = 0;
            } else {    
                quantity -= best_quantity; 
                orderBook.removeTopSellOrder();
            }
        } 
        if (quantity > 0) {
            std::shared_ptr<Order> new_order = std::make_shared<LimitOrder>(order.getOrderId(), quantity, price, OrderSide::BUY);
            orderBook.addOrder(new_order);
        }
    } else if (order.getSide() == OrderSide::SELL) {
        while (quantity > 0 && !orderBook.isBuyEmpty()) {
            double best_price = orderBook.getBestBuyPrice();
            
            if (best_price < price) {
                break;
            }

            std::shared_ptr<Order> best_order = orderBook.showTopBuyOrder(best_price);
            
            if (!best_order) {
                continue;
            }

            long best_quantity = best_order->getVolume();
            long difference = best_quantity - quantity;

            if (difference >= 0) {                
                best_order->setVolume(difference);
                quantity = 0;
            } else {    
                quantity -= best_quantity; 
                orderBook.removeTopBuyOrder();
            }
        } 
        if (quantity > 0) {
            std::shared_ptr<Order> new_order = std::make_shared<LimitOrder>(order.getOrderId(), quantity, price, OrderSide::SELL);
            orderBook.addOrder(new_order);
        }
    } else {
        throw std::invalid_argument("Invalid order side");
    }
}  

void MatchingEngine::visit(const FokOrder& order) {
    std::cout << "Processing Fok Order: ";
}

