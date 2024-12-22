#ifndef FIGURE_H
#define FIGURE_H
#include <SFML/Graphics.hpp>
// Базовый класс для всех фигур
class Figure {public:
    // Конструктор по умолчанию
Figure() = default;

// Виртуальный деструктор
virtual ~Figure() = default;

// Виртуальный метод для отрисовки фигуры (оставляем пустым)
virtual void draw(sf::RenderWindow& window) = 0;

// Виртуальный метод для перемещения фигуры
virtual void move(float x, float y) = 0;

// Виртуальный метод для проверки, содержит ли фигура точку
virtual bool contains(float x, float y) = 0;

// Виртуальный метод для получения центра фигуры
virtual sf::Vector2f getCenter() const = 0;
};
#endif
