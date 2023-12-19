#include "Cell.h"
#include "Config.h"
#include "Entity.h"
#include "Game.h"
#include "Position.h"
#include "Utils.h"

#include <iostream>
#include <vector>  // For vector
#include <string>
#include <termios.h>
#include <unistd.h>


int main() {
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