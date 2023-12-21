#include <iostream>
#include <vector>  // For vector
#include <string>
#include <termios.h>
#include <unistd.h>
#include "Class.h"
// #include <conio.h> // 用於_getch()來偵測按鍵
// #include <windows.h>  // uniX不能用...

using namespace std;
using namespace chrono;



// 函數用於 Linux 系統來讀取按鍵，使用 windows 系統時請註解掉
int getch() 
{
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




int main() 
{
    string name, anything;
    cout << "Enter your name: " << endl;
    cin >> name;
    // 忽略輸入名字後的回車，"回車"是指鍵盤上的 Enter 或 Return 鍵。
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl
         << "----------------- 遊戲規則 -------------------" << endl
	     << " " <<"I 代表 Ice, F 代表 Fire, ö 代表 Player, Player 要推 I 去熄滅 F" << endl
	     << " " <<"W 代表 Wall, $ 代表 $$" << endl
	     << " " <<"請使用 w, s, a, d 代表 ⬆︎, ⬇︎, ⬅︎, -> 來移動" << endl
	     << " " <<"總共會有四關，每一關要重新開始，請按 r !" << endl
	     << "---------------------------------------------" << endl
         << endl;
    cout << "First start practicing! Press anything to start." << endl;
    getch();    // 等待用戶按下任意按鍵

	int level = 0;
    // 創建 Game Instance
    Game game;
    // 用初始化函數來放置牆壁、冰塊和火焰
    game.initializeGameMap(game.getMap(), game.getPlayerPosition(),level); 
    // 因為地圖現在是由 Cell 組成的，countFires 函數也需要更新
    int totalFire = 0;
    totalFire = countFires(game.getMap()); // 初始化火焰數量
    // game.totalFire = countFires(game.getMap()); // 初始化火焰數量
    // 初次繪製地圖
    game.drawMap();  

    bool gameOver = false;
    while (!gameOver) {
        // 獲取按鍵輸入
        int input = getch(); 
        // 處理移動邏輯
        if (movePlayer(game, input, level))
		{
        	game.drawMap();
		}
		else
		{
			game.initializeGameMap(game.getMap(), game.getPlayerPosition(),level);
			game.drawMap();
		}
		
		if (countFires(game.getMap()) == 0){
            // 這邊使得到最後一關可以直接 break。但要小心 data inconsistency，之後若新增關卡要改掉，或是實作更加彈性的功能！
            if (level == 4)  // 結束條件
            {
                cout << "---------------------------------------------" << endl
                     << "Congrats, " << name << "!" << endl
                     << "You win!" << endl
                     << "---------------------------------------------" << endl
                     << "You completed the game in " << game.getTotalSteps() << " steps." << endl
                     << "Total money earned: " << game.getTotalMoney() << " dollars" << endl;
                drawHeart();
                break;
            }

            cout << "---------------------------------------------" << endl
			     << "Congrats, " << name << "!" << endl
                 << "You pass the level " << level << ", welcome to level "<< level + 1 << endl
                 << "You completed this level in " << game.getCurrentLevelSteps() << " steps." << endl
                 << "Total steps so far: " << game.getTotalSteps() << endl
                 << "You earned " << game.getCurrentLevelMoney() << " in this level." << endl
                 << "Total money so far: " << game.getTotalMoney() << endl
                 << endl
                 << "press anything to start level " << level + 1 << endl;
			
            level++;
            game.resetCurrentLevelSteps(); // 重置當前關卡步數
            game.resetCurrentLevelMoney(); // 重置當前關卡金錢
			game.initializeGameMap(game.getMap(), game.getPlayerPosition(), level);
		}
    }
    return 0;
}
