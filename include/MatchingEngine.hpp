#ifndef MATCHINGENGINE_HPP
#define MATCHINGENGINE_HPP

#include "OrderBook.hpp"

class MatchingEngine {
    private:
        OrderBook orderBook;
        
    public:
        // Public methods for matching engine operations
        void processOrder(const Order& order);
        void cancelOrder(int orderId);
};

#endif