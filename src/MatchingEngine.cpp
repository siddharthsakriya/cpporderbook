#include "MatchingEngine.hpp"
#include <iostream>
#include <memory>
#include "LimitOrder.hpp"
#include "MarketOrder.hpp"


void MatchingEngine::visit(const LimitOrder& order) {
    std::cout << "Processing Limit Order: ";    
}  

void MatchingEngine::visit(const MarketOrder& order) {
    std::cout << "Processing Market Order: ";
}

