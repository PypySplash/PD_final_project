#include "Cell.h"
#include "Config.h"
#include "Entity.h"
#include "Fire.h"
#include "Ice.h"
#include "Money.h"
#include "Position.h"
#include "Utils.h"
#include "Wall.h"
#include "Game.h"

#include <iostream>
#include <vector>  // For vector
#include <string>
#include <termios.h>
#include <unistd.h>

// 在這裡創建並設置(初始化) Entity 對象，i.e. 放置牆壁、冰塊和火焰
void Game::initializeGameMap(vector< vector<Cell> >& map, Position& playerPosition,int level) 
{
    resetCurrentLevelSteps();
    clearMessage();  // 清空先前的消息
    // ------------------- 創建方法如下：（要照這個邏輯來！） ---------------
    // map[y][x].setEntity(new Ice(x, y));
    // map[y][x].setEntity(new Fire(x, y));

    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            delete map[i][j].getEntity();  // 釋放每個 Cell 中的 Entity
            map[i][j].setEntity(nullptr);  // 確保指針被設置為 nullptr
        }
    }

    // 設置最外圍的牆壁：
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            // 檢查是否為邊界
            if (i == 0 || i == MAP_ROWS - 1 || j == 0 || j == MAP_COLS - 1) {
                map[i][j].setEntity(new Wall(j, i));
            }
        }
    }

    switch (level) 
    {
        case 0:
            addMessage("first start practicing!");
            // cout << "first start practicing!" << endl;
            playerPosition = Position(1, 1);  // 假設玩家開始在位置 (0, 2)
            map[2][3].setEntity(new Ice(3, 2));
            map[4][3].setEntity(new Fire(3, 4));
            break;
        case 1:
            playerPosition = Position(1, 1);
            for (int i = 0; i < MAP_ROWS; i++) 
            {	
                for (int j = 0; j < MAP_COLS; j++) 
                {
                    // 檢查是否為邊界
                    if (i == 0 || i == MAP_ROWS - 6 || j == 0 || j == MAP_COLS - 6) {
                        map[i][j].setEntity(new Wall(j, i));
                    }
                }
            }
            map[2][6].setEntity(new Ice(6, 2));
            map[3][2].setEntity(new Ice(2, 3));
            map[6][7].setEntity(new Ice(7, 6));
            map[7][3].setEntity(new Ice(3, 7));

            map[1][5].setEntity(new Fire(5, 1));
            map[4][1].setEntity(new Fire(1, 4));
            map[5][8].setEntity(new Fire(8, 5));
            map[8][4].setEntity(new Fire(4, 8));

            map[3][5].setEntity(new Money(5, 3));
            map[4][2].setEntity(new Money(2, 4));
            map[5][6].setEntity(new Money(6, 5));
            map[6][4].setEntity(new Money(4, 6));
            break;
        case 2:
            playerPosition = Position(5, 1);
            for (int i = 0; i < MAP_ROWS; i++) 
            {
                for (int j = 0; j < MAP_COLS; j++) 
                {
                    // 檢查是否為邊界
                    if (i == 0 || i == MAP_ROWS - 6 || j == 0 || j == MAP_COLS - 6) 
                    {
                        map[i][j].setEntity(new Wall(j, i));
                    }
                }
            }
            map[6][0].setEntity(new Wall(0, 6));
            map[6][1].setEntity(new Wall(6, 1));
            map[7][0].setEntity(new Wall(0, 7));
            map[7][1].setEntity(new Wall(1, 7));
            map[0][6].setEntity(new Wall(6, 0));
            map[0][7].setEntity(new Wall(7, 0));
            map[1][6].setEntity(new Wall(6, 1));
            map[1][7].setEntity(new Wall(7, 1));

            map[1][1].setEntity(new Ice(1, 1));
            map[2][2].setEntity(new Ice(2, 2));
            map[3][3].setEntity(new Ice(3, 3));
            map[5][5].setEntity(new Ice(5, 5));
            map[6][6].setEntity(new Ice(6, 6));
            map[7][7].setEntity(new Ice(7, 7));

            map[3][5].setEntity(new Fire(3, 5));
            map[4][3].setEntity(new Fire(4, 3));
            map[5][4].setEntity(new Fire(5, 4));

            map[2][4].setEntity(new Money(4,2));
            break;
        case 3:
            for (int i = 0; i < MAP_ROWS; i++) 	
            {    	
                for (int j = 0; j < MAP_COLS; j++) 
                {
                    // 檢查是否為邊界
                    if (i == 0 || i == MAP_ROWS - 5 || j == 0 || j == MAP_COLS - 5) 
                    {
                        map[i][j].setEntity(new Wall(j, i));
                    }
                }
            }
            playerPosition = Position(1, 1);
            map[8][2].setEntity(new Ice(2, 8));
            map[7][3].setEntity(new Ice(3, 7));
            map[6][4].setEntity(new Ice(4, 6));
            map[4][6].setEntity(new Ice(6, 4));
            map[3][7].setEntity(new Ice(7, 3));
            map[2][8].setEntity(new Ice(8, 2));
            //map[1][8].setEntity(new Wall(8, 1));
            map[5][5].setEntity(new Fire(5, 5));
            break;
        case 4:
            playerPosition = Position(1, 13);
            map[2][2].setEntity(new Wall(2, 2));
            map[2][3].setEntity(new Wall(3, 2));
            map[2][4].setEntity(new Wall(4, 2));
            map[2][5].setEntity(new Wall(5, 2));
            map[2][6].setEntity(new Wall(6, 2));
            map[2][9].setEntity(new Wall(9, 2));
            map[2][10].setEntity(new Wall(10, 2));
            map[2][11].setEntity(new Wall(11, 2));
            map[2][12].setEntity(new Wall(12, 2));
            map[2][13].setEntity(new Wall(13, 2));

            map[4][1].setEntity(new Wall(1, 4));
            map[4][2].setEntity(new Wall(2, 4));
            map[4][3].setEntity(new Wall(3, 4));
            map[4][4].setEntity(new Wall(4, 4));
            map[4][5].setEntity(new Wall(5, 4));
            map[4][6].setEntity(new Wall(6, 4));
            map[4][8].setEntity(new Wall(8, 4));
            map[4][9].setEntity(new Wall(9, 4));
            map[4][10].setEntity(new Wall(10, 4));
            map[4][11].setEntity(new Wall(11, 4));
            map[4][12].setEntity(new Wall(12, 4));

            map[6][2].setEntity(new Wall(2, 6));
            map[6][3].setEntity(new Wall(3, 6));
            map[6][4].setEntity(new Wall(4, 6));
            map[6][5].setEntity(new Wall(5, 6));
            map[6][6].setEntity(new Wall(6, 6));
            map[6][8].setEntity(new Wall(8, 6));
            map[6][9].setEntity(new Wall(9, 6));
            map[6][10].setEntity(new Wall(10, 6));
            map[6][11].setEntity(new Wall(11, 6));
            map[6][12].setEntity(new Wall(12, 6));
            map[6][13].setEntity(new Wall(13, 6));
            
            map[8][1].setEntity(new Wall(1, 8));
            map[8][2].setEntity(new Wall(2, 8));
            map[8][3].setEntity(new Wall(3, 8));
            map[8][4].setEntity(new Wall(3, 8));
            map[8][5].setEntity(new Wall(5, 8));
            map[8][6].setEntity(new Wall(6, 8));
            map[8][8].setEntity(new Wall(8, 8));
            map[8][9].setEntity(new Wall(9, 8));
            map[8][10].setEntity(new Wall(10, 8));
            map[8][11].setEntity(new Wall(11, 8));
            map[8][12].setEntity(new Wall(12, 8));
            
            map[10][2].setEntity(new Wall(2, 10));
            map[10][3].setEntity(new Wall(3, 10));
            map[10][4].setEntity(new Wall(4, 10));
            map[10][5].setEntity(new Wall(5, 10));
            map[10][6].setEntity(new Wall(6, 10));
            map[10][8].setEntity(new Wall(8, 10));
            map[10][9].setEntity(new Wall(9, 10));
            map[10][10].setEntity(new Wall(10, 10));
            map[10][11].setEntity(new Wall(11, 10));
            map[10][12].setEntity(new Wall(12, 10));
            map[10][13].setEntity(new Wall(13, 10));
            
            map[12][1].setEntity(new Ice(1, 12));
            map[12][2].setEntity(new Ice(2, 12));
            map[12][3].setEntity(new Ice(3, 12));
            map[12][4].setEntity(new Ice(4, 12));
            map[12][5].setEntity(new Ice(5, 12));
            map[12][6].setEntity(new Ice(6, 12));
            map[12][7].setEntity(new Ice(7, 12));
            map[12][8].setEntity(new Ice(8, 12));
            map[12][9].setEntity(new Ice(9, 12));
            map[12][10].setEntity(new Ice(10, 12));
            map[12][11].setEntity(new Ice(11, 12));
            map[12][12].setEntity(new Ice(12, 12));
            map[12][13].setEntity(new Ice(13, 12));

            map[1][2].setEntity(new Fire(2, 1));
            map[1][12].setEntity(new Fire(12, 1));
            map[3][2].setEntity(new Fire(2, 3));
            map[5][12].setEntity(new Fire(12, 5));
            map[7][2].setEntity(new Fire(2, 7));
            map[9][12].setEntity(new Fire(12, 9));

            map[2][7].setEntity(new Money(7, 2));
            map[2][8].setEntity(new Money(8, 2));
            map[4][7].setEntity(new Money(7, 4));
            map[6][7].setEntity(new Money(7, 6));
            map[8][7].setEntity(new Money(7, 8));
            /* 
            Method 1:
            7 上、右，吃最下面的物件，5 上 6 右、上、左，吃最下面的物件，3 上 4 右，解題關鍵 *** 1 上 2 右 ***、上、右，
            吃最下面的物件， 9 上 8 左、上、左，吃最後兩個物件，11 上 10 左、上、左，13 上 12 左、上、右
            Method 2:
            7 上、右，吃最下面的物件，8 上
            6 上、右、吃最下面的物件
            5 上、右、吃最下面的物件
            以此類推...（右邊只會用到8）*/
            break;
        default:  // 如果 level 不匹配上述任何一個值
            break;
    }
}
// 初始化地圖和其他元素
Game::Game() : map(MAP_ROWS, vector<Cell>(MAP_COLS)), playerPosition(0, 0), currentLevelMoney(0), totalMoney(0), currentLevelSteps(0), totalSteps(0) 
{
    initializeGameMap(map, playerPosition, 0);
}
Game::~Game()
{
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            delete map[i][j].getEntity();  // 釋放每個 Cell 中的 Entity
            map[i][j].setEntity(nullptr);  // 確保指針被設置為 nullptr
        }
    }
}
vector< vector<Cell> >& Game::getMap() 
{
    return map;
}
Position& Game::getPlayerPosition()
{
    return playerPosition;
}
Position Game::getPlayerDirection() const 
{
    return playerDirection;
}
void Game::setPlayerDirection(const Position& dir) 
{
    playerDirection = dir;
}
void Game::extinguishFire(int x, int y) 
{
    // 檢查指定位置的 Cell 是否包含 Fire
    Entity* entity = map[y][x].getEntity();
    if (entity != nullptr && dynamic_cast<Fire*>(entity) != nullptr) {
        // 移除火焰
        delete entity;  // 首先釋放記憶體
        map[y][x].setEntity(nullptr);  // 然後將 Cell 的 entity 指針設置為 nullptr
        addMessage("A fire has been extinguished!");
    }
}
// 添加消息的方法
void Game::addMessage(const string& msg) 
{
    message += msg + "\n";
}
// 清空消息的方法
void Game::clearMessage() 
{
    message = "";
}
void Game::earnMoney(int amount) 
{
    currentLevelMoney += amount;
    totalMoney += amount;
}
int Game::getCurrentLevelMoney() const 
{
    return currentLevelMoney;
}
int Game::getTotalMoney() const 
{
    return totalMoney;
}
void Game::collectMoney(int x,int y) 
{
    // 檢查指定位置的 Cell 是否包含 Money
    Entity* entity = map[y][x].getEntity();
    if (entity != nullptr && dynamic_cast<Money*>(entity) != nullptr) {
        delete entity; // 首先釋放記憶體
        map[y][x].setEntity(nullptr); // 然後將 Cell 的 entity 指針設置為 nullptr
        earnMoney(100);  // 每撿到一個道具賺100塊
        addMessage("A Money has been collected!");
    }
}
void Game::drawMap()
{
    // 清屏（不清屏才會有提示文字跑出來
    cout << "\x1B[2J\x1B[H";
    for (int i = 0; i < MAP_ROWS; i++) {  // i 表示 y 座標
        for (int j = 0; j < MAP_COLS; j++) {  // j 表示 x 座標
            if (playerPosition.x == j && playerPosition.y == i) 
            {
                // 在這邊處理玩家的初始化，因為玩家並不是一個 class，也不需要是，只需要是一個符號，可以被移動即可
                cout << "ö" << " ";
            }
            else if (!map[i][j].isEmpty()) 
            {
                // 顯示其他實體符號
                cout << map[i][j].getEntity()->getMapSymbol() << " ";
            }
            else 
            {
                cout << "." << " "; // 空格用 '.' 表示
            }
        }
        cout << endl;
    }
    // 顯示消息
    cout << "Messages:" << endl;
    cout << message;
    // 可选：在此处清空消息
    clearMessage();
}
bool Game::isPositionValid(const Position& pos) 
{
    return pos.x >= 0 && pos.x < MAP_COLS && pos.y >= 0 && pos.y < MAP_ROWS;
}
bool Game::isObstacleAt(const Position& pos) 
{
    Entity* entity = map[pos.y][pos.x].getEntity();
    if (entity != nullptr) {
        // 檢查實體是否為牆壁或另一個冰塊
        char symbol = entity->getMapSymbol();  // polymorphism (?，拿 parent 的指標指向 child (?
        return symbol == 'W' || symbol == 'I' || symbol == '$'; // *change 假設 'W' 代表牆壁，'I' 代表冰塊，'$'代表物品
    }
    return false;
}
bool Game::isFireAt(const Position& pos) 
{
    // 使用 dynamic_cast<Fire*>(entity) 嘗試將獲取的 Entity 對象轉換為 Fire 類型的指針。
    // 如果 entity 真的是 Fire 類型的對象，則這個轉換會成功，返回一個非空指針。如果不是，則返回 nullptr。
    Entity* entity = map[pos.y][pos.x].getEntity();
    return entity != nullptr && dynamic_cast<Fire*>(entity) != nullptr;
}
void Game::updateEntityPosition(Entity* entity, const Position& oldPos, const Position& newPos) 
{
    if (isPositionValid(newPos)) {
        // 移除舊位置的實體
        map[oldPos.y][oldPos.x].setEntity(nullptr);
        // 將實體設置到新位置
        map[newPos.y][newPos.x].setEntity(entity);
    }
}
void Game::incrementSteps() 
{
    currentLevelSteps++;
    totalSteps++;
}
int Game::getCurrentLevelSteps() const 
{
    return currentLevelSteps;
}
int Game::getTotalSteps() const 
{
    return totalSteps;
}
void Game::resetCurrentLevel() 
{
    totalMoney -= currentLevelMoney;
    totalSteps -= currentLevelSteps;

    resetCurrentLevelMoney();
    resetCurrentLevelSteps();
}
void Game::resetCurrentLevelMoney() 
{
    currentLevelMoney = 0;
}
void Game::resetCurrentLevelSteps() 
{
    currentLevelSteps = 0;
}



bool movePlayer(Game& game, char move, int& level) 
{
    Position& playerPos = game.getPlayerPosition();
    vector< vector<Cell> >& map = game.getMap();
    Position newDirection;  // 新的移動方向

    try
    {
        // 根據輸入的移動方向更新玩家的新位置
        switch(move) 
        {
    	case 'r': 
            game.resetCurrentLevel();
            game.initializeGameMap(game.getMap(), game.getPlayerPosition(), level);
            game.drawMap();
            return false;
        case 'w': newDirection = Position(0, -1); break;  // 上
        case 's': newDirection = Position(0, 1); break;   // 下
        case 'a': newDirection = Position(-1, 0); break;  // 左
        case 'd': newDirection = Position(1, 0); break;   // 右
        default: throw invalid_argument("Invalid button!");
        }
    }
    catch (const invalid_argument& e)
    {
        game.addMessage("An exception occurred: " + string(e.what()));
        return true;  // 保持在遊戲循環中
    }

    // 計算新位置
    int newX = playerPos.x + newDirection.x;
    int newY = playerPos.y + newDirection.y;

    // // 檢查新位置是否超出地圖範圍 （但因為現在最外圈會加上牆壁，故這邊可先註解掉）
    // if (newX < 0 || newX >= MAP_COLS || newY < 0 || newY >= MAP_ROWS) {
    //     cout << "You can't move there!" << endl;
    //     return true;
    // }

    // 更新玩家方向
    game.setPlayerDirection(newDirection);

    Cell& newCell = map[newY][newX];

    // 檢查新位置是否有 Entity
    if (!newCell.isEmpty()) {
        Entity* entity = newCell.getEntity();
        // auto 用於自動推導變數的類型，在 polymorphism 中是一種常用的方法
        // 例如當一個變數可以指向基類 (Entity) 的多個派生類別 (Ice), (Money) 的實例
        if (auto ice = dynamic_cast<Ice*>(entity)) {
            // 如果新位置有冰塊，則嘗試觸發冰塊的 interact 方法
            Position oldIcePosition = ice->getPosition();
            ice->interact(game);
            // 檢查冰塊位置是否改變
            if (oldIcePosition == ice->getPosition())
            {
                // 冰塊未移動，玩家也不移動
                game.addMessage("Ice block is immovable!");
                // cout << "Ice block is immovable!" << endl;
            }
            else 
            {
                // 冰塊移動了，更新玩家位置
                map[playerPos.y][playerPos.x].setEntity(nullptr);
                playerPos.x = newX;
                playerPos.y = newY;
                game.incrementSteps();
            }
        }
        else if (auto ice = dynamic_cast<Money*>(entity)) 
        {  // *change
            game.collectMoney(newX, newY);
            game.getMap()[playerPos.y][playerPos.x].setEntity(nullptr);
            playerPos.x = newX;
            playerPos.y = newY;
            game.incrementSteps();
        }
        else 
        {
            // 如果新位置有其他實體（例如火焰或牆壁），則不移動玩家
            game.addMessage("Cannot move there!");
            // cout << "Cannot move there!" << endl;
        }
    }
    // 如果新位置沒有實體，則直接移動玩家
    else 
    {
        map[playerPos.y][playerPos.x].setEntity(nullptr);
        playerPos.x = newX;
        playerPos.y = newY;
        game.incrementSteps();
    }
    return true;
}



int countFires(const vector< vector<Cell> >& map) 
{
    int fireCount = 0;
    for (int i = 0; i < map.size(); i++) 
    {
        for (int j = 0; j < map[i].size(); j++) 
        {
            Entity* entity = map[i][j].getEntity();
            if (entity != nullptr && dynamic_cast<Fire*>(entity) != nullptr) 
            {
                fireCount++;
            }
        }
    }
    return fireCount;
}



void drawHeart()
{
    int i, j, n = 0, c = 0;
    while(n != 3) 
    {
        n += 1;
        if (n == 3) 
        {
            // system("color 1");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < 30 - 2 * c; j++)
                    cout << ' ';
                for(j = 0; j < n - i; j++)
                    cout << ' ';
                for(j = 0; j < 2 * (i + 1) - 1; j++)
                    cout << '*';
                for(j = 0; j < 2 * (n - i); j++)
                    cout << ' ';
                for(j = 0; j < 2 * (1 + i) - 1; j++)
                    cout << '*';
                cout << '\n';
            }
            int x = (2 * (n + 1) - 1) * 2;
            for(i = 0; i < x / 2; i++)
            {
                for(j = 0; j < 30 - 2 * c; j++)
                    cout << ' ';
                for(j = 0; j < i; j++)
                    cout << ' ';
                for(j = 0; j < x - 2 * i; j++)
                    cout << '*';
                cout << '\n';
            }
            // cout << '\n' << '\n' << '\n';
            c++;
            // usleep(1000 * 1000);  // 1000毫秒的延遲
            if(n > 10) n=-1;
        }
    }
}