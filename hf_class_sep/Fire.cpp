#include "Entity.h"
#include "Fire.h"

// Fire 方法的實現
Fire::Fire(int x, int y) : Entity(x, y) {}

char Fire::getMapSymbol() const {
    return 'F';
}

void Fire::interact(Game& game) {
    // 在這裡實現 Fire 的交互邏輯
}