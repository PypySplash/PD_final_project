#ifndef ENTITY_H
#define ENTITY_H

#include "Position.h"
class Game;  // 前向聲明

class Entity {
protected:
    Position position;
public:
    Entity(int x, int y);
    virtual ~Entity();
    virtual char getMapSymbol() const = 0;
    virtual void interact(Game& game) = 0;
    void setPosition(const Position& newPos);
    Position getPosition() const;
};

#endif // ENTITY_H
