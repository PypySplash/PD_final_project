#include "Entity.h"
class Game;  // 前向聲明

class Ice : public Entity
{
private:
public:
    Ice(int x, int y) : Entity(x, y) {}
    char getMapSymbol() const override;
    // Ice interact 函數放在 Game 後面，因為牽扯到執行順序的問題，之後試著放到頭文件裡去改善
    void interact(Game& game) override;
};