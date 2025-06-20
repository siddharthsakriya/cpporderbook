#include "OrderVisitor.hpp"
#include "FokOrder.hpp"

void FokOrder::accept(OrderVisitor& visitor) const {
    visitor.visit(*this);
}