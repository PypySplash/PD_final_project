#include "Cell.h"

Cell::Cell() : entity(nullptr) {}

Cell::~Cell() {
    delete entity; // 確保釋放資源
}

Entity* Cell::getEntity() const {
    return entity;
}

void Cell::setEntity(Entity* e) {
    entity = e;
}

bool Cell::isEmpty() const {
    return entity == nullptr;
}