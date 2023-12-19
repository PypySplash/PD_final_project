#include "Entity.h"
#include "Game.h"  // 包含 Game 以取得完整定義



void Entity::setPosition(const Position& newPos) 
{
    position = newPos;
}
Position Entity::getPosition() const 
{
    return position;
}
