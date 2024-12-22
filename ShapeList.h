#ifndef SHAPELIST_H
#define SHAPELIST_H
#include <vector>
#include "Figure.h"
// Класс, хранящий список фигур
class ShapeList {private:
std::vector<Figure*> shapes_;
public:
    // Добавление фигуры в список
    void addShape(Figure* shape);

    // Отрисовка всех фигур
    void drawAll(sf::RenderWindow& window);

    ~ShapeList();

    // Перемещение выбранной фигуры
    void moveSelected(int index, float x, float y);

    // Получение фигуры по индексу
    Figure* getShape(int index);

    // Проверка, содержит ли какая-либо фигура точку
    int contains(float x, float y);

    // Количество фигур в списке
    int size();
};
#endif
