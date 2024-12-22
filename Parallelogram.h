#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "Figure.h"
// Класс, представляющий параллелограмм
class Parallelogram : public Figure {private:
sf::Vector2f position_;
sf::Vector2f size_;
float angle_;
    sf::Color color_; public:
        // Конструктор с параметрами
        Parallelogram(float x, float y, float width, float height, float angle, const sf::Color& color = sf::Color::Black) :
            position_({ x, y }), size_({ width, height }), angle_(angle), color_(color) {}

        // Метод для отрисовки параллелограмма
        void draw(sf::RenderWindow& window) override;

        // Метод для перемещения параллелограмма
        void move(float x, float y) override;

        bool contains(float x, float y) override;

        sf::Vector2f getCenter() const override;
};
#endif
