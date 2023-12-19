#include "Entity.h"

class Wall : public Entity
{
private:
public:
    Wall(int x, int y) : Entity(x, y) {}
    char getMapSymbol() const override;
    void interact(Game& game) override {}  // 牆壁不需要有交互作用
};