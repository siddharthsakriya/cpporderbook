// main.cpp
#include <iostream>
#include <memory>
#include "MatchingEngine.hpp"
#include "LimitOrder.hpp"

int main() {
    MatchingEngine engine;

    engine.processOrder(LimitOrder(1, 100, 100.0, OrderSide::BUY));
    engine.printOrderBook();

    engine.processOrder(LimitOrder(2, 40,  90.0,  OrderSide::SELL));
    engine.printOrderBook();

    engine.processOrder(LimitOrder(3, 70, 100.0,  OrderSide::SELL));
    engine.printOrderBook();

    return 0;
}
