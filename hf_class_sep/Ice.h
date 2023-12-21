#include "Entity.h"
class Game;  // 前向聲明

// Ice 類別
class Ice : public Entity
{
public:
    Ice(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};