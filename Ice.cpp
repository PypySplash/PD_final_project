#include "Game.h"
#include "Ice.h"

void Ice::interact(Game &game)
{
    Position pos = getPosition();
    // 確定冰塊的移動方向
    // 假設玩家推動的方向存儲在某個變量中，這裡用 playerDirection 代替
    Position playerDirection = game.getPlayerDirection();

    while (true) {
        pos.x += playerDirection.x;
        pos.y += playerDirection.y;

        // 檢查新位置是否超出地圖範圍或是否遇到障礙物
        if (!game.isPositionValid(pos) || game.isObstacleAt(pos)) {
            // 回退到上一個有效位置
            pos.x -= playerDirection.x;
            pos.y -= playerDirection.y;
            break;
        }

        // 更新冰塊位置
        setPosition(pos);

        // 檢查是否遇到火焰
        if (game.isFireAt(pos)) {
            game.extinguishFire(pos.x, pos.y);
            break;
        }
    }
}