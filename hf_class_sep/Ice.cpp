#include "Entity.h"
#include "Ice.h"
#include "Game.h"



Ice::Ice(int x, int y) : Entity(x, y) {}

char Ice::getMapSymbol() const 
{
    return 'I';
}
// 這邊之後要改用頭文件！！！
void Ice::interact(Game& game) {
    Position pos = getPosition();  // 獲取冰塊當前位置
    Position playerDirection = game.getPlayerDirection();  // 玩家推動方向

    while (true) {
        // 計算冰塊新位置
        Position newPos(pos.x + playerDirection.x, pos.y + playerDirection.y);
        // 檢查新位置是否超出地圖範圍或是否有障礙物（另一個冰塊或牆壁）
        if (!game.isPositionValid(newPos) || game.isObstacleAt(newPos)) 
        {
            // 如果新位置不合法或有障礙物，停止移動
            break;
        }

        // 如果新位置是火焰
        if (game.isFireAt(newPos)) {
            // 熄滅火焰並移除冰塊
            game.extinguishFire(newPos.x, newPos.y);
            game.getMap()[pos.y][pos.x].setEntity(nullptr); // 移除舊位置的冰塊
            delete this; // 刪除冰塊對象
            break; // 停止冰塊的進一步移動
        }

        // 將冰塊移動到新位置
        game.updateEntityPosition(this, pos, newPos);
        setPosition(newPos);
        pos = newPos; // 更新當前位置
    }
}