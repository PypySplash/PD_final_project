#include "Entity.h"

// Money 類別
class Money : public Entity
{
public:
    Money(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};