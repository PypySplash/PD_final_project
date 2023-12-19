#include "Entity.h"

class Money : public Entity  // change
{
private:
public:
    Money(int x, int y) : Entity(x, y) {}
    char getMapSymbol() const override;
    void interact(Game& game) override {}
};