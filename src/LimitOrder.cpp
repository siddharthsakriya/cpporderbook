#include "OrderVisitor.hpp"
#include "LimitOrder.hpp"

void LimitOrder::accept(OrderVisitor& visitor) const {
    visitor.visit(*this);
}