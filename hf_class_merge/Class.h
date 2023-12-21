#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <string>

using namespace std;

const int MAP_ROWS = 15;
const int MAP_COLS = 15;

class Game;

// 定義 Position 結構
struct Position 
{
    int x, y;
    Position(int x = 0, int y = 0);
    bool operator==(const Position& other) const;
};

// Entity 基類
class Entity
{
protected:
    Position position;
public:
    Entity(int x, int y);
    virtual ~Entity();
    virtual char getMapSymbol() const = 0;
    virtual void interact(Game& game) = 0;
    void setPosition(const Position& newPos);
    Position getPosition() const;
};

// Ice 類別
class Ice : public Entity
{
public:
    Ice(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};

// Fire 類別
class Fire : public Entity
{
public:
    Fire(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};

// Wall 類別
class Wall : public Entity
{
public:
    Wall(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};

// Money 類別
class Money : public Entity
{
public:
    Money(int x, int y);
    char getMapSymbol() const override;
    void interact(Game& game) override;
};

// Cell 類別
class Cell
{
private:
    Entity* entity;
public:
    Cell();
    Entity* getEntity() const;
    void setEntity(Entity* e);
    bool isEmpty() const;
};

// Game 類別
class Game 
{
private:
    vector< vector<Cell> > map;
    Position playerPosition;
    Position playerDirection;
    string message;
    int currentLevelMoney;
    int totalMoney;
    int currentLevelSteps;
    int totalSteps;
public:
    Game();
    ~Game();
    void initializeGameMap(vector< vector<Cell> >& map, Position& playerPosition, int level);
    vector< vector<Cell> >& getMap();
    Position& getPlayerPosition();
    Position getPlayerDirection() const;
    void setPlayerDirection(const Position& dir);
    void extinguishFire(int x, int y);
    void addMessage(const std::string& msg);
    void clearMessage();
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
    void incrementSteps();
    void resetCurrentLevelSteps();
    int getCurrentLevelSteps() const;
    int getTotalSteps() const;
    void resetCurrentLevel();
};

// bool movePlayer(Game& game, char move, int& level);
// int countFires(const vector< vector<Cell> >& map);
// void drawHeart();

#endif // CLASS_H
