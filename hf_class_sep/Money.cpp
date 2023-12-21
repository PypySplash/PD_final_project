#include "Entity.h"
#include "Money.h"

// Money 方法的實現
Money::Money(int x, int y) : Entity(x, y) {}

char Money::getMapSymbol() const {
    return '$';
}

void Money::interact(Game& game) {
    // 在這裡實現 Money 的交互邏輯
}