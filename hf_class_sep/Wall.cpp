#include "Entity.h"
#include "Wall.h"

// Wall 方法的實現
Wall::Wall(int x, int y) : Entity(x, y) {}

char Wall::getMapSymbol() const {
    return 'W';
}

void Wall::interact(Game& game) {
    // 在這裡實現 Wall 的交互邏輯
}
