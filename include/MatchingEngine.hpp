#ifndef MATCHINGENGINE_HPP
#define MATCHINGENGINE_HPP

#include "OrderBook.hpp"
#include "OrderVisitor.hpp"

class MatchingEngine : public OrderVisitor {
    private:
        OrderBook orderBook;
        
    public:
        MatchingEngine() = default;
        void processOrder(const Order& order) { order.accept(*this); };
        void visit(const LimitOrder& order);
        void visit(const MarketOrder& order);
};

#endif