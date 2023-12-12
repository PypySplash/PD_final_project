#include <iostream>
#include <utility> // For pair
#include <vector>  // For vector
#include <string>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
// #include <conio.h> // 用於_getch()來偵測按鍵
using namespace std;

// 函數用於Linux系統來讀取按鍵
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

const int MAP_ROWS = 10;
const int MAP_COLS = 10;

// 一個簡單的二維座標結構
struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class Entity 
{
protected:
    Position position; // 使用Position結構來代替pair
public:
    // 更新位置的方法
    void changeLocation(int x, int y) {
        position.x = x;
        position.y = y;
    }
    // 獲取位置的方法
    Position getPosition() const {return position;}
};

class Ice : public Entity
{
private:
public:
};

class Fire : public Entity 
{
private:
public:
};

class Wall {
private:
    Position position;
public:
    Wall(int x, int y) : position(x, y) {}
    Position getPosition() const {return position;}
};

class Item 
{
private:
    Position position;
    string name;
    int specialNumber; // 特殊編號
public:
    Item(const string& n, int x, int y, int specialNum) : name(n), position(x, y), specialNumber(specialNum) {}
    string getName() const {return name;}
    int getSpecialNumber() const {return specialNumber;}
};

class Game {
private:
    vector< vector<char> > map;
    Position playerPosition; // 角色位置
    vector<Ice> ices;
    vector<Fire> fires;
    vector<Item> items;
    vector<Wall> walls;
public:
    
    Game() : map(MAP_ROWS, vector<char>(MAP_COLS, '0')), playerPosition(0, 0) {
        // 初始化地圖和其他元素
    }
    // 修改getPlayerPosition方法，使其返回一个引用
    Position& getPlayerPosition() {
        return playerPosition;
    }

    // 添加getMap方法，返回地图的引用
    vector< vector<char> >& getMap() {
        return map;
    }

    int totalFire; // 遊戲中火焰的總數
    void extinguishFire(int x, int y) {
        // 假設地圖上火焰的位置用 'F' 表示
        if (map[y][x] == 'F') {
            map[y][x] = '.'; // 移除火焰
            totalFire--; // 更新火焰總數
            cout << "A fire has been extinguished!" << endl;
        }
    }

    void drawMap() {
        // 清除終端的一種跨平台的方法
        cout << "\x1B[2J\x1B[H";

        // 遍歷地圖並繪製每個元素
        for (int i = 0; i < MAP_ROWS; i++) {
            for (int j = 0; j < MAP_COLS; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
    // 遊戲邏輯和方法...
};

// 在這裡添加冰塊和火焰的初始化
void initializeGameMap(vector< vector<char> >& map) {
    map.resize(MAP_ROWS, vector<char>(MAP_COLS, '0'));  // 以'0'填充代表空地
    // 在這裡放置牆壁、冰塊和火焰
    // 例如：
    // map[1][1] = 'I';  // 在(1, 1)位置放置一個冰塊
    // map[2][2] = 'F';  // 在(2, 2)位置放置一個火焰
    // map[0][0] = 'W';  // 在(0, 0)位置放置一個牆壁
    // 可以根據遊戲設計添加更多元素
}

void movePlayer(Game& game, char move) {
    Position& playerPos = game.getPlayerPosition();
    vector< vector<char> >& map = game.getMap();
    int newX = playerPos.x;
    int newY = playerPos.y;

    // 根據輸入的移動方向更新玩家的新位置
    switch(move) {
        case 'w': newY--; break; // 上
        case 's': newY++; break; // 下
        case 'a': newX--; break; // 左
        case 'd': newX++; break; // 右
        default: cout << "Invalid move!" << endl; return;
    }

    // 檢查新位置是否超出地圖範圍
    if (newX < 0 || newX >= MAP_COLS || newY < 0 || newY >= MAP_ROWS) {
        cout << "You can't move there!" << endl;
        return;
    }

    char& newPos = map[newY][newX];

    // 根據新位置的元素決定是否移動
    if (newPos == 'W') 
    {
        cout << "There's a wall here!" << endl;
    }
    if (newPos == 'F') 
    {
        cout << "There's a fire here!" << endl;
    } 
    // 如果新位置是冰塊
    if (newPos == 'I') {
        // 確定推動方向
        int dirX = newX - playerPos.x;
        int dirY = newY - playerPos.y;

        while (true) {
            // 計算冰塊下一個位置
            newX += dirX;
            newY += dirY;

            // 檢查冰塊下一個位置是否超出地圖範圍或遇到牆壁
            if (newX < 0 || newX >= MAP_COLS || newY < 0 || newY >= MAP_ROWS || map[newY][newX] == 'W') {
                newX -= dirX; // 回退到上一個有效位置
                newY -= dirY;
                map[playerPos.y][playerPos.x] = '.'; // 清除玩家原來的位置
                map[newY][newX] = '.'; // 清除冰塊，因為它不能進入牆壁
                playerPos.x = newX; // 更新玩家位置到冰塊推動前的位置
                playerPos.y = newY;
                map[playerPos.y][playerPos.x] = 'P'; // 玩家移動到新位置
                break; // 結束推動
            }

            // 如果冰塊下一個位置是火焰
            if (map[newY][newX] == 'F') {
                game.extinguishFire(newX, newY); // 熄滅火焰
                map[playerPos.y][playerPos.x] = '.'; // 清除玩家原來的位置
                map[newY][newX] = '.'; // 清除冰塊，因為它熄滅了火焰
                playerPos.x = newX - dirX; // 更新玩家位置到冰塊推動前的位置
                playerPos.y = newY - dirY;
                map[playerPos.y][playerPos.x] = 'P'; // 玩家移動到新位置
                break; // 結束推動
            }
        }
    }
    else {
        // 移動玩家到新位置
        map[playerPos.y][playerPos.x] = '.'; // 清除舊位置
        playerPos.x = newX; // 更新玩家位置
        playerPos.y = newY;
        newPos = 'P'; // 在新位置放置玩家
    }
}

int main()
{
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;

    Game game;
    initializeGameMap(game.getMap()); // 用初始化函數來放置牆壁、冰塊和火焰
    bool gameOver = false;
    game.totalFire = countFires(game.getMap()); // 初始化火焰數量

    game.drawMap(); // 初次繪製地圖

    while (!gameOver) {
        int input = getch(); // 獲取按鍵輸入

        if (input == 27) { // 如果是Esc按鍵 (ASCII值27)
            // 第i關重新開始的邏輯
            continue;
        }

        // 處理移動邏輯
        movePlayer(game, input);

        game.drawMap(); // 更新並繪製地圖

        // ...其他邏輯...
    }


    return 0;
}
