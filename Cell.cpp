#include "Cell.h"

#include <iostream>
#include <vector>  // For vector
#include <string>
#include <termios.h>
#include <unistd.h>
// #include <conio.h> // 用於_getch()來偵測按鍵
// #include <windows.h>  // uniX不能用...

// using namespace std;
// using namespace chrono;

Entity* Cell::getEntity() const {
    return entity;
}

void Cell::setEntity(Entity* e) {
    entity = e;
}

bool Cell::isEmpty() const 
{
    return entity == nullptr;
}