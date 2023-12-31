#include <iostream>
#include <utility> // For pair
#include <vector>  // For vector
#include <string>
#include <chrono>
#include <thread>
//#include <termios.h>
#include <unistd.h>
#include <stdio.h>
 #include <conio.h> // 用於_getch()來偵測按鍵
 #include <windows.h>  // uniX不能用...
using namespace std;
const int MAP_ROWS = 11;
const int MAP_COLS = 11;

//// 函數用於Linux系統來讀取按鍵
//int getch() {
//    struct termios oldt, newt;
//    int ch;
//    tcgetattr(STDIN_FILENO, &oldt);
//    newt = oldt;
//    newt.c_lflag &= ~(ICANON | ECHO);
//    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//    ch = getchar();
//    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//    return ch;
//}

// 一個簡單的二維座標結構
struct Position {
    int x;  // 列
    int y;  // 行
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    // 比較兩個位置是否相同
    bool equals(const Position& other) const {return x == other.x && y == other.y;}
};

class Game;
class Entity
{
protected:
    Position position; // 使用Position結構來代替pair
public:
    Entity(int x, int y) : position(x, y) {}
    virtual ~Entity() {}  // 虛擬析構函數
    // 獲取位置的方法
    Position getPosition() const {return position;}
    void setPosition(const Position& newPos) {position = newPos;}
    virtual char getMapSymbol() const = 0; // 純虛擬函數，用於返回地圖上的符號
    virtual void interact(Game& game) = 0; // 用於與玩家交互的方法
};
class Ice : public Entity
{
private:
public:
    Ice(int x, int y) : Entity(x, y) {}
    char getMapSymbol() const override {return 'I';}
    void interact(Game& game) override;
};
class Fire : public Entity
{
private:
public:
    Fire(int x, int y) : Entity(x, y) {}
    char getMapSymbol() const override { return 'F'; }
    void interact(Game& game) override {
        // 實現火焰的交互邏輯
        // 比如：熄滅火焰
    }
};
class Wall : public Entity
{
private:
    // Position position;
public:
    Wall(int x, int y) : Entity(x, y) {}
    char getMapSymbol() const override {return 'W';}  // 假設牆壁在地圖上的表示為 'W'
    void interact(Game& game) override {}
    // Position getPosition() const {return position;}
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



class Cell {
private:
    Entity* entity; // 指向 Entity 對象的指針
public:
    Cell() : entity(nullptr) {} // 默認構造函數
    void setEntity(Entity* e) {entity = e;}
    Entity* getEntity() const {return entity;}
    bool isEmpty() const {return entity == nullptr;}
};



// 在這裡添加冰塊和火焰的初始化
void initializeGameMap(vector< vector<Cell> >& map, Position& playerPosition,int level) {
    // 在這裡放置牆壁、冰塊和火焰
    // 創建並設置 Entity 對象
    // ------------------- 創建方法如下：（要照這個邏輯來！） ---------------
    // map[y][x].setEntity(new Ice(x, y));
    // map[y][x].setEntity(new Fire(x, y));
    // level 0:
    // playerPosition = Position(1, 1);  // 假設玩家開始在位置 (0, 2)
    // map[2][3].setEntity(new Ice(3, 2));
    // map[4][3].setEntity(new Fire(3, 4));
    // 在地圖邊界設置牆壁
    
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            delete map[i][j].getEntity();  // 釋放每個 Cell 中的 Entity
            map[i][j].setEntity(nullptr);  // 確保指針被設置為 nullptr
        }
    }
    
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            // 檢查是否為邊界
            if (i == 0 || i == MAP_ROWS - 1 || j == 0 || j == MAP_COLS - 1) {
                map[i][j].setEntity(new Wall(j, i));
            }
        }
    }
    // level 1:
    if(level==1){
    	playerPosition = Position(1, 1);
	    map[7][1].setEntity(new Ice(1, 7));
	    map[6][2].setEntity(new Ice(2, 6));
	    map[5][3].setEntity(new Ice(3, 5));
	    map[3][5].setEntity(new Ice(5, 3));
	    map[2][6].setEntity(new Ice(6, 2));
	    map[1][7].setEntity(new Ice(7, 1));
	    map[5][5].setEntity(new Ice(5, 5));
	    map[4][4].setEntity(new Fire(4, 4));
	}
	if(level==2){
    	playerPosition = Position(1, 1);
	    map[7][1].setEntity(new Ice(1, 7));
	    map[6][2].setEntity(new Ice(2, 6));
	    map[5][3].setEntity(new Ice(3, 5));
	}

    // level 3....:




    // 可以根據遊戲設計添加更多元素
}



class Game {
private:
    vector< vector<Cell> > map; // 使用 Cell 類別來存儲地圖數據
    Position playerPosition; // 角色位置
    Position playerDirection;
    vector<Ice> ices;
    vector<Fire> fires;
    vector<Item> items;
    vector<Wall> walls;
public:
    Game() : map(MAP_ROWS, vector<Cell>(MAP_COLS)), playerPosition(0, 0) {
        // 初始化地圖和其他元素
        initializeGameMap(map, playerPosition,1);
    }
    ~Game()
    {
        for (int i = 0; i < MAP_ROWS; i++) {
            for (int j = 0; j < MAP_COLS; j++) {
                delete map[i][j].getEntity();  // 釋放每個 Cell 中的 Entity
                map[i][j].setEntity(nullptr);  // 確保指針被設置為 nullptr
            }
        }
    }
    void setPlayerDirection(const Position& dir) {playerDirection = dir;}
    Position getPlayerDirection() const {return playerDirection;}
    // 修改getPlayerPosition方法，使其返回一个引用
    Position& getPlayerPosition() {return playerPosition;}
    // 添加getMap方法，返回地图的引用
    vector< vector<Cell> >& getMap() {
        return map;
    }

    int totalFire; // 遊戲中火焰的總數
    void extinguishFire(int x, int y) {
        // 檢查指定位置的 Cell 是否包含火焰
        Entity* entity = map[y][x].getEntity();
        if (entity != nullptr && dynamic_cast<Fire*>(entity) != nullptr) {
            // 移除火焰
            delete entity; // 首先釋放記憶體
            map[y][x].setEntity(nullptr); // 然後將 Cell 的 entity 指針設置為 nullptr

            totalFire--; // 更新火焰總數
            cout << "A fire has been extinguished!" << endl;
        }
    }

    void drawMap()
    {
        cout << "\x1B[2J\x1B[H"; // 清屏
        for (int i = 0; i < MAP_ROWS; i++) {  // i表示y座標
            for (int j = 0; j < MAP_COLS; j++) {  // j表示x座標
                if (playerPosition.x == j && playerPosition.y == i) {
                    cout << 'P' << " "; // 在玩家位置顯示 'P'
                } else if (!map[i][j].isEmpty()) {
                    cout << map[i][j].getEntity()->getMapSymbol() << " "; // 顯示其他實體符號
                } else {
                    cout << "." << " "; // 空格用 '.' 表示
                }
            }
            cout << endl;
        }
    }
    bool isPositionValid(const Position& pos);
    bool isObstacleAt(const Position& pos);
    bool isFireAt(const Position& pos);
    void updateEntityPosition(Entity* entity, const Position& oldPos, const Position& newPos) {
        if (isPositionValid(newPos)) {
            // 移除舊位置的實體
            map[oldPos.y][oldPos.x].setEntity(nullptr);
            // 將實體設置到新位置
            map[newPos.y][newPos.x].setEntity(entity);
        }
    }
};
bool Game::isPositionValid(const Position& pos) {
    return pos.x >= 0 && pos.x < MAP_COLS && pos.y >= 0 && pos.y < MAP_ROWS;
}
bool Game::isObstacleAt(const Position& pos) {
    Entity* entity = map[pos.y][pos.x].getEntity();
    if (entity != nullptr) {
        // 檢查實體是否為牆壁或另一個冰塊
        // 假設 Wall 和 Ice 有 getMapSymbol 方法
        char symbol = entity->getMapSymbol();
        return symbol == 'W' || symbol == 'I'; // 假設 'W' 代表牆壁，'I' 代表冰塊
    }
    return false;
}
bool Game::isFireAt(const Position& pos) {
    Entity* entity = map[pos.y][pos.x].getEntity();
    return entity != nullptr && dynamic_cast<Fire*>(entity) != nullptr;
}


// 這邊之後要改用頭文件！！！
void Ice::interact(Game& game) {
    Position pos = getPosition();  // 獲取冰塊當前位置
    Position playerDirection = game.getPlayerDirection();  // 玩家推動方向

    while (true) {
        Position newPos(pos.x + playerDirection.x, pos.y + playerDirection.y); // 計算冰塊新位置

        // 檢查新位置是否超出地圖範圍或是否有障礙物（另一個冰塊或牆壁）
        if (!game.isPositionValid(newPos) || game.isObstacleAt(newPos)) {
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



bool movePlayer(Game& game, char move) {
    Position& playerPos = game.getPlayerPosition();
    vector< vector<Cell> >& map = game.getMap();
    Position newDirection;  // 新的移动方向

    // 根據輸入的移動方向更新玩家的新位置
    switch(move) {
    	case 'r': return false;
        case 'w': newDirection = Position(0, -1); break;  // 上
        case 's': newDirection = Position(0, 1); break;   // 下
        case 'a': newDirection = Position(-1, 0); break;  // 左
        case 'd': newDirection = Position(1, 0); break;   // 右
        default: cout << "Invalid move!" << endl; return true;
    }

    // 计算新位置
    int newX = playerPos.x + newDirection.x;
    int newY = playerPos.y + newDirection.y;
    // 檢查新位置是否超出地圖範圍
    if (newX < 0 || newX >= MAP_COLS || newY < 0 || newY >= MAP_ROWS) {
        cout << "You can't move there!" << endl;
        return true;
    }
    // 更新玩家方向
    game.setPlayerDirection(newDirection);

    Cell& newCell = map[newY][newX];

    // 檢查新位置是否有 Entity
    if (!newCell.isEmpty()) {
        Entity* entity = newCell.getEntity();
        if (auto ice = dynamic_cast<Ice*>(entity)) {
            // 如果新位置有冰塊，則嘗試觸發冰塊的 interact 方法
            Position oldIcePosition = ice->getPosition();
            ice->interact(game);

            // 檢查冰塊位置是否改變
            if(oldIcePosition.equals(ice->getPosition())) {
                // 冰塊未移動，玩家也不移動
                cout << "Ice block is immovable!" << endl;
            } else {
                // 冰塊移動了，更新玩家位置
                map[playerPos.y][playerPos.x].setEntity(nullptr);
                playerPos.x = newX;
                playerPos.y = newY;
            }
        }
        else {
            // 如果新位置有其他實體（例如火焰或牆壁），則不移動玩家
            cout << "Cannot move there!" << endl;
        }
    } else {
        // 如果新位置沒有實體，則直接移動玩家
        map[playerPos.y][playerPos.x].setEntity(nullptr);
        playerPos.x = newX;
        playerPos.y = newY;
    }
    return true;
}



int countFires(const vector< vector<Cell> >& map) {
    int fireCount = 0;
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            Entity* entity = map[i][j].getEntity();
            if (entity != nullptr && dynamic_cast<Fire*>(entity) != nullptr) {
                fireCount++;
            }
        }
    }
    return fireCount;
}



int main() {
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;

	int level =1;
    Game game; // 創建遊戲實例
    initializeGameMap(game.getMap(), game.getPlayerPosition(),level); // 用初始化函數來放置牆壁、冰塊和火焰
    // 因為地圖現在是由 Cell 組成的，countFires 函數也需要更新
    game.totalFire = countFires(game.getMap()); // 初始化火焰數量
    game.drawMap(); // 初次繪製地圖

    bool gameOver = false;
    while (!gameOver) {
        int input = getch(); // 獲取按鍵輸入
        if (input == 27) { // 如果是Esc按鍵 (ASCII值27)
            // 第i關重新開始的邏輯
            continue;
        }
        // 處理移動邏輯
        if(movePlayer(game, input)){
        	game.drawMap();
		}
		else{
			initializeGameMap(game.getMap(), game.getPlayerPosition(),level);
			game.drawMap();
		}
		if(countFires(game.getMap())==0){
			cout << "Congrats! you won, welcome to level"<< level <<endl << "press any thing to continue";
			level++;
			initializeGameMap(game.getMap(), game.getPlayerPosition(),level);
		}
// 更新並繪製地圖
        // ...其他邏輯，比如檢查遊戲是否結束...
    }
    return 0;
}
