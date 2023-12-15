#include "Entity.h" // 包含 Entity 的聲明
class Game; // 前向聲明 Game

class Ice : public Entity {
public:
    Ice(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};
