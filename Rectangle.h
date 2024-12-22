#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
// Класс, представляющий прямоугольник
class Rectangle : public Figure {private:
sf::Vector2f position_;
sf::Vector2f size_;
sf::Color color_;
public:
    // Конструктор с параметрами
    Rectangle(float x, float y, float width, float height, const sf::Color& color = sf::Color::Black) :
        position_({ x, y }), size_({ width, height }), color_(color) {}


    // Метод для отрисовки прямоугольника
    void draw(sf::RenderWindow& window) override;

    // Метод для перемещения прямоугольника
    void move(float x, float y) override;

    bool contains(float x, float y) override;
    sf::Vector2f getCenter() const override;
};
#endif
