#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Figure.h"
// Класс, представляющий эллипс
class Ellipse : public Figure {private:
sf::Vector2f center_;
sf::Vector2f radius_;
    sf::Color color_; public:
        // Конструктор с параметрами
        Ellipse(float x, float y, float radiusX, float radiusY, const sf::Color& color = sf::Color::Black) :
            center_({ x, y }), radius_({ radiusX, radiusY }), color_(color) {}

        // Метод для отрисовки эллипса
        void draw(sf::RenderWindow& window) override;

        // Метод для перемещения эллипса
        void move(float x, float y) override;
        bool contains(float x, float y) override;
        sf::Vector2f getCenter() const override;
};
#endif
