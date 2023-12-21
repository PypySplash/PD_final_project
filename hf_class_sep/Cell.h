#ifndef CELL_H
#define CELL_H

#include "Entity.h" // 假設你的 Entity 類也是定義在另一個文件中

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

#endif // CELL_H