#include "Entity.h"
#include "Game.h"  // 包含 Game 以取得完整定義



// Entity 方法的實現
Entity::Entity(int x, int y) : position(x, y) {}

Entity::~Entity() {}

void Entity::setPosition(const Position& newPos) {
    position = newPos;
}

Position Entity::getPosition() const {
    return position;
}


