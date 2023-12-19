#ifndef POSITION_H
#define POSITION_H

struct Position {
    int x;  // 列
    int y;  // 行
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Position& other) const;
};

#endif // POSITION_H
