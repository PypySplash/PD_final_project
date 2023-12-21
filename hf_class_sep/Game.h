#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include "Cell.h"
#include <vector>
#include <string>

using namespace std;

class Game 
{
private:
    vector< vector<Cell> > map; // 使用 Cell 類別來存儲地圖數據
    Position playerPosition; // 角色位置
    Position playerDirection;
    string message; // 用于存储游戏消息
    int currentLevelMoney;  // 當前關卡賺取的金錢
    int totalMoney;         // 遊戲進行中累計的總金錢
    int currentLevelSteps; // 當前關卡步數
    int totalSteps; // 總步數
    int savedTotalMoney;    // 儲存重啟前的總金錢
    int savedTotalSteps;    // 儲存重啟前的總步數
public:
    void initializeGameMap(vector< vector<Cell> >& map, Position& playerPosition,int level);
    Game();
    ~Game();
    vector< vector<Cell> >& getMap();
    Position& getPlayerPosition();
    Position getPlayerDirection() const;
    void setPlayerDirection(const Position& dir);
    void extinguishFire(int x, int y);
    void addMessage(const string& msg);  // 添加消息的方法
    void clearMessage();  // 清空消息的方法
    void resetCurrentLevelMoney();
    void earnMoney(int amount);
    int getCurrentLevelMoney() const;
    int getTotalMoney() const;
    void collectMoney(int x,int y);
    void drawMap();
    bool isPositionValid(const Position& pos);
    bool isObstacleAt(const Position& pos);
    bool isFireAt(const Position& pos);
    void updateEntityPosition(Entity* entity, const Position& oldPos, const Position& newPos);
    void incrementSteps(); // 增加步數的方法
    void resetCurrentLevelSteps(); // 重置當前關卡步數的方法
    int getCurrentLevelSteps() const; // 獲取當前關卡步數的方法
    int getTotalSteps() const; // 獲取總步數的方法
    void resetCurrentLevel(); // 新增方法
};

bool movePlayer(Game& game, char move, int& level);
int countFires(const vector< vector<Cell> >& map);
void drawHeart();

#endif // GAME_H