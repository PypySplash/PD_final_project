#ifndef CELL_H
#define CELL_H

#include "Entity.h" // 假設你的 Entity 類也是定義在另一個文件中

class Cell {
private:
    Entity* entity; // 指向 Entity 對象的指針

public:
    Cell(); // Constructor
    // ~Cell(); // Destructor
    Entity* getEntity() const;
    void setEntity(Entity* e);
    bool isEmpty() const;
};

#endif // CELL_H