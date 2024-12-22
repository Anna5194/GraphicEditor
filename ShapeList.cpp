#include "ShapeList.h"
void ShapeList::addShape(Figure* shape) {
    shapes_.push_back(shape);
}
void ShapeList::drawAll(sf::RenderWindow& window) {
    for (Figure* shape : shapes_) {
        shape->draw(window);
    }
}

ShapeList::~ShapeList() {
    for (Figure* shape : shapes_) {
        delete shape;
    }
}
void ShapeList::moveSelected(int index, float x, float y) {
    if (index >= 0 && index < shapes_.size()) {
        shapes_[index]->move(x, y);
    }
}Figure* ShapeList::getShape(int index) {
    if (index >= 0 && index < shapes_.size()) {
        return shapes_[index];
    }
    return nullptr;
}
int ShapeList::contains(float x, float y) {
    for (int i = 0; i < shapes_.size(); i++) {
        if (shapes_[i]->contains(x, y)) {
            return i;
        }
    }
    return -1;
}
int ShapeList::size() {
    return shapes_.size();
}
