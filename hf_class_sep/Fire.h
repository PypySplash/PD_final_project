#include "Entity.h"

class Fire : public Entity
{
private:
public:
    Fire(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override; // 實現火焰的交互邏輯
};