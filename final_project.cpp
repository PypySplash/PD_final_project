#include <iostream>
#include <utility> // For pair
#include <vector>  // For vector
#include <string>
#include <chrono>
#include <thread>
using namespace std;

const int MAP_ROWS = 10;
const int MAP_COLS = 10;

// �@��²�檺�G���y�е��c
struct Position {
    int x;
    int y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class Character
{
protected:
    string name;
    int health;
    Position position; // �ϥ�Position���c�ӥN��pair
public:
    Character(const string& n, int hp, int x, int y)
    : name(n), health(hp), position(x, y) {}
    string getName() const {return name;}
    int getHealth () const {return health;}
    // ��s��m����k
    void changeLocation(int x, int y) {
        position.x = x;
        position.y = y;
    }
    // �����m����k
    Position getPosition() const {return position;}

    virtual void attack(Character& target) = 0;
};

class Player : public Character
{
private:
    int level;
    int experience;
    int specialNumber; // �S��s���A�����D�㪺�Ʀr
public:
    Player(const string& n, int x, int y, int specialNum)
    : Character(n, 100, x, y), level(0), experience(0), specialNumber(specialNum) {}
    int getExperience () const {return experience;}
    void levelUp(int gainedExperience) {
        experience += gainedExperience; // �K�[��o���g��Ȩ��e�g���
        while (experience >= 100)
        {  // ��g��Ȩ����ɯŮɡA�i�J�`��
            level++; // �ɤ@��
            experience -= 100; // ��h�ɯũһݪ��g���
            health += 1; // ���]�C�ɤ@�šA�W�[1�I�ͩR��
            // �i�H�b�o�̲K�[��L�ɯ��޿�A�p�W�[�����O�B���m�O��
        }
    }
    void attack(Character& target) override {
        // Perform player's attack logic
    }
};

class Enemy : public Character
{
public:
    Enemy(const string& n, int hp, int x, int y) : Character(n, hp, x, y) {}
    void attack(Character& target) override {
        // Perform enemy's attack logic
    }
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
    int specialNumber; // �S��s��
public:
    Item(const string& n, int x, int y, int specialNum) : name(n), position(x, y), specialNumber(specialNum) {}
    string getName() const {return name;}
    int getSpecialNumber() const {return specialNumber;}
};

class Game
{
private:
    Player player;
    vector<Enemy> enemies;
    vector<Item> items;
    vector<Wall> walls;
public:
    Game(const string& playerName, int playerX, int playerY, int playerSpecialNumber)
    : player(playerName, playerX, playerY, playerSpecialNumber) {}

    void addEnemy(const Enemy& enemy) {enemies.push_back(enemy);}
    void addItem(const Item& item) {items.push_back(item);}
    void addWall(const Wall& wall) {walls.push_back(wall);}
    // Game logic methods
};

void initializeGameMap(vector<vector<char> >& map) {
    map.resize(MAP_ROWS, vector<char>(MAP_COLS, '0')); // �H'0'��R�N��Ŧa
    // �i�H�b�o�̩�m����M��L����
}

// ø�s�C���ɭ�
void drawGame(const string& playerName, int totalEnemyHealth, const vector<vector<char> >& map) {
    system("clear"); // �M�̡A���Windows�ϥ�system("cls");

    // ø�s�W�r�M�p�ɾ��b�k�W��
    cout << string(50, ' ') << "Player: " << playerName << " Time: " << "00:00" << endl;

    // ø�s totalEnemyHealth �b���W��
    cout << "Total Enemy Health: " << totalEnemyHealth << endl;

    // ø�s�C���a��
    for (const auto& row : map) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

void movePlayer(char direction, vector<vector<char> >& map, Player& player, int& totalEnemyHealth) {
    Position playerPos = player.getPosition();
    int newX = playerPos.x;
    int newY = playerPos.y;

    // �T�w�s����m
    switch (direction) {
        case 'W': newY--; break; // �V�W����
        case 'A': newX--; break; // �V������
        case 'S': newY++; break; // �V�U����
        case 'D': newX++; break; // �V�k����
    }

    // �ˬd�s��m�O�_�W�X�a�Ͻd��
    if (newX < 0 || newX >= MAP_COLS || newY < 0 || newY >= MAP_ROWS) {
        return; // �p�G�W�X�d��A���i�沾��
    }

    // �ھڪ������ʧ@
    switch (map[newY][newX]) {
        case '0': // �Ŧa�A�i�H����
            map[playerPos.y][playerPos.x] = '0'; // �M���¦�m
            player.changeLocation(newX, newY); // ��s���a��m
            map[newY][newX] = 'P'; // �b�s��m��m���a
            break;
        case 'W': // ��A������
            break;
        case 'F': // ���A�i��԰�
            totalEnemyHealth -= 10; // ��ּĤH�`��q
            if (totalEnemyHealth <= 0) {
                map[newY][newX] = '.'; // �M���ĤH��m
            }
            // �b�o�̳B�z�P�����԰��޿�
            // ���totalEnemyHealth�A�p�G�B�Τ���q�k�s�A��s�a��
            break;
        case 'I': // �B�A�i�H���ʡA�i���ٻݭn�椬
            // ���]���ʦB���A�B���|�ƨ�U�@��A���D�U�@��O���
            int nextX = newX, nextY = newY;
            switch (direction) {
                case 'W': nextY--; break;
                case 'A': nextX--; break;
                case 'S': nextY++; break;
                case 'D': nextX++; break;
            }
            if (nextX >= 0 && nextX < MAP_COLS && nextY >= 0 && nextY < MAP_ROWS
                && map[nextY][nextX] == '.') {
                map[newY][newX] = '.'; // �M����Ӫ��B��
                map[nextY][nextX] = 'I'; // �B���ƨ�s��m
            }
            // ���a���ʨ�B�����m
            map[playerPos.y][playerPos.x] = '.'; // �M���¦�m
            player.changeLocation(newX, newY); // ��s���a��m
            map[newY][newX] = 'P'; // ���a���ʨ�B����m
            break;
            // �b�o�̳B�z�P�B���椬�޿�
        // ... ��L���p ...
    }
}

int main()
{
    string name;
    cout << "�п�J�W�r: ";
    cin >> name;

    // ��l�ƹC���a��
    vector<vector<char> > gameMap;
    initializeGameMap(gameMap);

    // ��l�ƪ��a��m�M�S��s��
    int playerX = 0; // �ݭn�ھڹC���]�p�ӫ��w��l��
    int playerY = 0; // �ݭn�ھڹC���]�p�ӫ��w��l��
    int playerSpecialNumber = 1; // ���]����l�S��s��

    // �ЫعC�����
    Player player(name, 0, 0, 1); // ���]���a��l��m�b(0, 0)
    // Game game(name, 0, 0, 1); // ���]���a��l��m��(0,0)�A�S��s����1

    // �[�J�ĤH�B���~�M������C����H
    // �o�̻ݭn�ھڨC�����d���]�p�ӰʺA�K�[
    // game.addEnemy(Enemy("Fire", 10, 1, 1));
    // game.addItem(Item("Ice Shard", 2, 2, 5));
    // game.addWall(Wall(3, 3));

    // �C���D�`��
    int totalEnemyHealth = 100; // ���]���ĤH�`��q
    bool gameOver = false;

    while (!gameOver) {
        char input;
        cout << "�п�J���ʫ��O (WASD): ";
        cin >> input;

        // �ھڿ�J��s�C�����A
        switch (input) {
            case 'W': // �V�W����
                // ��s���a��m
                // ���ʪ��a
                movePlayer(input, gameMap, player, totalEnemyHealth);
                // �ˬd�O�_�L��
                if (totalEnemyHealth <= 0) {
                    cout << "Congratulations! You've completed the level." << endl;
                    // �i�J�U�@���ε����C��
                    gameOver = true; // ���]�C������
                }
                break;
            case 'A': // �V������
                // ��s���a��m
                break;
            case 'S': // �V�U����
                // ��s���a��m
                break;
            case 'D': // �V�k����
                // ��s���a��m
                break;
            case 'E': // �S��ʧ@�A�Ҧp����
                // ��������޿�
                break;
            case 'Q': // ���}�C��
                gameOver = true;
                break;
            default:
                cout << "�L�Ī���J!" << endl;
                break;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
    // �C�������B�z...
    cout << "�C�������A" << name << " ���o���O: " << /* ���a�o�� */ endl;
    // ...��L�����޿�

    return 0;
}
